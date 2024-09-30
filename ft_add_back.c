/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouveia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:32:32 by cgouveia          #+#    #+#             */
/*   Updated: 2024/09/30 12:35:29 by cgouveia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_stack_lstlast(*stack))->next = stack_new;
}

void	fill_index(t_stack **a)
{
	t_stack		*tmp;
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

void	aproximacao(t_stack **a)
{
	int	index_min;

	index_min = ft_find_index(*a, ft_min(*a));
	if (index_min < ft_stack_lstsize(*a) / 2)
		while ((*a)->nbr != ft_min(*a))
			ft_ra(a, 0);
	else
		while ((*a)->nbr != ft_min(*a))
			ft_rra(a, 0);
}

void	aproximacao1(t_stack **b)
{
	int	index_max;

	index_max = ft_find_index(*b, ft_max(*b));
	if (index_max < ft_stack_lstsize(*b) / 2)
		while ((*b)->nbr != ft_max(*b))
			ft_rb(b, 0);
	else
		while ((*b)->nbr != ft_max(*b))
			ft_rrb(b, 0);
}
