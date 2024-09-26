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
	else if (ft_max(*a) > (*a)->nbr)
	{
		ft_rra(a, 0);
		if (!ft_checksorted(*a))
			ft_sa(a, 0);
	}
	
}

void algor (t_stack **a, t_stack **b)
{
	/*printf("antes aproximacao A:\n");
	print_stack(*a);
	printf("antes aproximacao B:\n");
	print_stack(*b);*/
	while (ft_stack_lstsize(*a) > 3)
	{
		fill_index(a);
		if (!ft_checksorted(*a))
		{
			aproximacao(a);
			ft_pb(a, b, 0);
		}
	}
	/*printf("Apos aproximacao A:\n");
	print_stack(*a);
	printf("Apos aproximacao B:\n");
	print_stack(*b);*/
	if (!ft_checksorted(*a) && ft_stack_lstsize(*a) == 3)
		sort_true(a);
	while (*b)
	{
		ft_pa(a, b, 0);
	}
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

void algor1_aux(t_stack **a, t_stack **b)
{
	int	index_min;
	long	aux;

	aux = (*a)->key_nbr;
	while ((long)ft_min(*a) <= aux)
	{
		fill_index(a);
		index_min = ft_find_index(*a, ft_min(*a));
		if ((index_min < ft_stack_lstsize(*a) / 2))
		{
			while ((*a)->nbr != ft_min(*a))
				ft_ra(a, 0);
		}
		else
		{
			while ((*a)->nbr != ft_min(*a))
				ft_rra(a, 0);
		}
		ft_pb(a, b, 0);
	}
}

void	algor1(t_stack **a, t_stack **b)
{
	long	*vet;
	long		div;
	long		tm;

	div = 1;
	vet = fill_vet_pilha(*a, &tm);
	while (div < 4 && !ft_checksorted(*a) && ft_stack_lstsize(*a) > 10)
	{
		(*a)->key_nbr = vet[((div * tm) / 4) - 1];
		//printf("div: %ld e tm : %ld key: %ld\n", div, tm, (*a)->key_nbr);
		while ((*a)->key_nbr > ft_min(*a))
		{
			algor1_aux(a, b);
			
		}
		/*printf("Apos algor A: v\n");
		print_stack(*a);
		printf("Apos algor B: v\n");
		print_stack(*b);*/
		div++;
	}
	if (!ft_checksorted(*a))
	{
		fill_index(a);
		algor(a, b);
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
	if (!ft_checksorted(a))
	{
		fill_index(&a);
		if (ft_stack_lstsize(a)  <= 10)
		{
			algor(&a, &b);
		}
		else if ((ft_stack_lstsize(a) > 10) && (ft_stack_lstsize(a) <= 100))
			algor1(&a, &b);
	}
	/*printf("Apos fim:\n");
	print_stack(a);
	printf("Apos fim:\n");
	print_stack(b);*/
	ft_free(&a);
	return (0);
}
