/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouveia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:35:56 by cgouveia          #+#    #+#             */
/*   Updated: 2024/09/30 13:09:50 by cgouveia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	last = ft_stack_lstlast(tmp);
	last->next = tmp;
	tmp->next = NULL;
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
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	ft_rrr_sub(b, j);
}
