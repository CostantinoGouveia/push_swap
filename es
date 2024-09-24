#include "push_swap.h"

// Função para rotacionar pilha a
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

// Função para rotacionar pilha b
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

// Função para rotacionar pilhas a e b simultaneamente
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

// Função para trocar os dois primeiros elementos da pilha a
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

// Função para trocar os dois primeiros elementos da pilha b
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

// Função para trocar os dois primeiros elementos de a e b simultaneamente
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

// Função para enviar o topo da pilha b para o topo da pilha a
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

// Função para enviar o topo da pilha a para o topo da pilha b
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

// Função para rotacionar reverso a pilha a
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

// Função para rotacionar reverso a pilha b
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

// Função auxiliar para rotacionar reverso a pilha b dentro da função rrr
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

// Função para rotacionar reverso pilhas a e b simultaneamente
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
