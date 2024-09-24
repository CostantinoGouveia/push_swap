#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Definição da estrutura da pilha
typedef struct s_stack {
    int value;
    struct s_stack *next;
} t_stack;


t_stack	*ft_stack_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_stack_lstsize(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
// Funções de manipulação de pilhas (inclua as que você forneceu anteriormente)

// ... (código das funções ft_rr, ft_rrr, ft_pb, ft_rb, ft_sb, ft_ra, ft_sa, ft_pa, ft_rra, ft_ss)

void	ft_rr(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;

	// Rotacionar pilha a
	tmp = *a;
	*a = (*a)->next;
	last = ft_stack_lstlast(tmp);
	last->next = tmp;
	tmp->next = NULL;

	// Rotacionar pilha b
	tmp = *b;
	*b = (*b)->next;
	last = ft_stack_lstlast(tmp);
	last->next = tmp;
	tmp->next = NULL;

	if (j == 0)
		write(1, "rr\n", 3);
}

void	ft_rrr_sub(t_stack **b, int j)
{
	t_stack	*prev;
	t_stack	*last;

	if (!*b || !(*b)->next)
		return ;

	last = *b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;

	if (j == 0)
		write(1, "rrr\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b, int j)
{
	t_stack	*prev;
	t_stack	*last;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;

	// Rotacionar reverso a
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;

	// Rotacionar reverso b
	ft_rrr_sub(b, j);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b, int j)
{
	t_stack	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
	if (j == 0)
		write(1, "pb\n", 3);
}

void	ft_rrb(t_stack **b, int j)
{
	t_stack	*prev;
	t_stack	*last;

	if (!*b || !((*b)->next))
		return ;
	last = *b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;

	if (j == 0)
		write(1, "rrb\n", 4);
}

void	ft_rb(t_stack **b, int j)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	last = ft_stack_lstlast(tmp);
	last->next = tmp;
	tmp->next = NULL;
	if (j == 0)
		write(1, "rb\n", 3);
}

void	ft_sb(t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (j == 0)
		write(1, "sb\n", 3);
}


void	ft_ra(t_stack **a, int j)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	last = ft_stack_lstlast(tmp);
	last->next = tmp;
	tmp->next = NULL;
	if (j == 0)
		write(1, "ra\n", 3);
}

void	ft_sa(t_stack **a, int j)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (j == 0)
		write(1, "sa\n", 3);
}

void	ft_pa(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	if (j == 0)
		write(1, "pa\n", 3);
}

void	ft_rra(t_stack **a, int j)
{
	t_stack	*prev;
	t_stack	*last;

	if (!*a || !((*a)->next))
		return ;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;

	if (j == 0)
		write(1, "rra\n", 4);
}

void	ft_ss(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;

	// Troca em a
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;

	// Troca em b
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;

	if (j == 0)
		write(1, "ss\n", 3);
}

// Função para criar um novo nó
t_stack *create_node(int value) {
    t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Função para imprimir a pilha
void print_stack(t_stack *stack) {
    if (!stack) {
        printf("Stack is empty\n");
        return;
    }
    while (stack) {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

// Função principal
int main() {
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;
    int choice, value;

    // Inicialização de stack_a com alguns valores
    for (int i = 5; i > 0; i--) {
        t_stack *new_node = create_node(i);
        new_node->next = stack_a;
        stack_a = new_node;
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Rotate stack A (ra)\n");
        printf("2. Rotate stack B (rb)\n");
        printf("3. Push from A to B (pb)\n");
        printf("4. Push from B to A (pa)\n");
        printf("5. Swap stack A (sa)\n");
        printf("6. Swap stack B (sb)\n");
        printf("7. Rotate both stacks (rr)\n");
        printf("8. Reverse rotate stack A (rra)\n");
        printf("9. Reverse rotate stack B (rrb)\n");
        printf("10. Exit\n");
        printf("Choose an operation: ");
        scanf("%d", &choice);

        if (choice == 10) {
            break; // Saia do loop
        }

        // Imprime o estado atual das pilhas
        printf("Stack A: ");
        print_stack(stack_a);
        printf("Stack B: ");
        print_stack(stack_b);

        switch (choice) {
            case 1:
                ft_ra(&stack_a, 0);
                break;
            case 2:
                ft_rb(&stack_b, 0);
                break;
            case 3:
                ft_pb(&stack_a, &stack_b, 0);
                break;
            case 4:
                ft_pa(&stack_a, &stack_b, 0);
                break;
            case 5:
                ft_sa(&stack_a, 0);
                break;
            case 6:
                ft_sb(&stack_b, 0);
                break;
            case 7:
                ft_rr(&stack_a, &stack_b, 0);
                break;
            case 8:
                ft_rra(&stack_a, 0);
                break;
            case 9:
                ft_rrb(&stack_b, 0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
                continue;
        }

        // Imprime o estado das pilhas após a operação
        printf("After operation:\n");
        printf("Stack A: ");
        print_stack(stack_a);
        printf("Stack B: ");
        print_stack(stack_b);
    }

    // Libere a memória da pilha
    while (stack_a) {
        t_stack *tmp = stack_a;
        stack_a = stack_a->next;
        free(tmp);
    }
    while (stack_b) {
        t_stack *tmp = stack_b;
        stack_b = stack_b->next;
        free(tmp);
    }

    return 0;
}
