#include "push_swap.h"
void fill_index(t_stack **a)
{
	t_stack	*tmp;
	long		i;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

int	ft_find_index(t_stack *a, int nbr)
{
	int		i;

	while (a->nbr != nbr)
	{
		i = a->index;
		a = a->next;
	}
	return (i);
}

void aproximacao (t_stack **a)
{
	int index_min;

	index_min = ft_find_index(*a, ft_min(*a));
	if (index_min < ft_stack_lstsize(*a) / 2)
	{
		while ((*a)->nbr != ft_min(*a))
			ft_ra(a, 0);
	}
	else
	{
		while ((*a)->nbr != ft_min(*a))
			ft_rra(a, 0);
	}
}

void sort_true (t_stack **a)
{
	if (ft_min(*a) == (*a)->nbr)
	{
		ft_rra(a, 0);
		ft_sa(a, 0);
	}
	else if (ft_max(*a) == (*a)->nbr)
	{
		ft_ra(a, 0);
		if (!ft_checksorted(*a))
			ft_sa(a, 0);
	}
	else
	{
		if (ft_find_index(*a, ft_max(*a)) == 1)
			ft_rra(a, 0);
		else
			ft_sa(a, 0);
	}
}

void algor (t_stack **a, t_stack **b)
{
	printf("antes aproximacao A:\n");
	print_stack(*a);
	printf("antes aproximacao B:\n");
	print_stack(*b);
	while (!ft_checksorted(*a) && ft_stack_lstsize(*a) > 3)
	{
		aproximacao(a);
		//ft_pb(a, b, 0);
		//fill_index(a);
		break ;
	}
	printf("Apos aproximacao A:\n");
	print_stack(*a);
	printf("Apos aproximacao B:\n");
	print_stack(*b);
	if (!ft_checksorted(*a) && ft_stack_lstsize(*a) == 3)
		sort_true(a);
}

void print_stack(t_stack *stack) {
    if (!stack) {
        printf("Stack is empty\n");
        return;
    }
    while (stack) {
        printf("%ld ", stack->nbr);
        stack = stack->next;
    }
    printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = ft_process(argc, argv);
	if (!a || ft_checkdup(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_checksorted(a))
	{
		fill_index(&a);
		algor(&a, &b);
	}
	printf("Apos algor:\n");
	print_stack(a);
	ft_free(&a);
	return (0);
}
