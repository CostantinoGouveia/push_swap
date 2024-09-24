#include "push_swap.h"

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