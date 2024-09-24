#include "push_swap.h"

void	ft_ra(t_stack **a, int j)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	last = ft_stack_lstlast(tmp);
	*a = (*a)->next;
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
