#include "push_swap.h"
void fill_index(t_stack **a)
{
	t_stack	*tmp;
	int		i;

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

	i = 0;
	while (a->nbr != nbr)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}

void aproximacao (t_stack *a)
{
	int index_min;

	index_min = ft_find_index(a, ft_min(a));
	if (index_min < ft_stack_lstsize(a) / 2)
	{
		while (a->nbr != ft_min(a))
			ft_ra(&a, 0);
	}
	else
	{
		while (a->nbr != ft_min(a))
			ft_rra(&a, 0);
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
	while (!ft_checksorted(*a) && ft_stack_lstsize(*a) > 3)
	{
		aproximacao(*a);
		ft_pb(a, b, 0);
	}
	if (!ft_checksorted(*a) && ft_stack_lstsize(*a) == 3)
		sort_true(a);
}

void print_stack(t_stack *a)
{
	while (a)
	{
		printf("# %ld\n", a->nbr);
		a = a->next;
	}
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
	//print_stack(a);
	if (!ft_checksorted(a))
	{
		fill_index(&a);
		algor(&a, &b);
	}
	printf("Stack: A\n");
	print_stack(a);
	printf("Stack: B\n");
	print_stack(b);
	ft_free(&a);
	return (0);
}
