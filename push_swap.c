/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouveia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:57:46 by cgouveia          #+#    #+#             */
/*   Updated: 2024/09/30 12:57:52 by cgouveia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_true(t_stack **a)
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
	else if (ft_max(*a) == (*a)->next->nbr)
	{
		ft_rra(a, 0);
		if (!ft_checksorted(*a))
			ft_sa(a, 0);
	}
	else
		ft_sa(a, 0);
}

void	algor(t_stack **a, t_stack **b)
{
	while (ft_stack_lstsize(*a) > 3 && !ft_checksorted(*a))
	{
		fill_index(a);
		aproximacao(a);
		ft_pb(a, b, 0);
	}
	if (!ft_checksorted(*a) && ft_stack_lstsize(*a) == 3)
		sort_true(a);
	while (*b)
	{
		if (ft_max(*b) == (*b)->nbr)
			ft_pa(a, b, 0);
		else if (ft_max(*b) == (*b)->next->nbr)
		{
			ft_sb(b, 0);
			ft_pa(a, b, 0);
		}
		else
		{
			fill_index(b);
			aproximacao1(b);
		}
	}
}

void	algor1_aux(t_stack **a, t_stack **b)
{
	int		index_min;
	long	aux;
	t_stack	*tmp;

	aux = (*a)->key_nbr;
	tmp = *a;
	while (tmp)
	{
		if (tmp->nbr <= aux)
		{
			fill_index(a);
			index_min = ft_find_index(*a, tmp->nbr);
			if ((index_min < ft_stack_lstsize(*a) / 2))
				while ((*a)->nbr != tmp->nbr)
					ft_ra(a, 0);
			else
				while ((*a)->nbr != tmp->nbr)
					ft_rra(a, 0);
			while (*a && (*a)->nbr <= aux)
				ft_pb(a, b, 0);
			tmp = *a;
		}
		tmp = tmp->next;
	}
}

void	algor1(t_stack **a, t_stack **b, long dec)
{
	long	*vet;
	long	div;
	long	tm;

	div = 1;
	vet = fill_vet_pilha(*a, &tm);
	while (div < dec && !ft_checksorted(*a) && ft_stack_lstsize(*a) > 10)
	{
		(*a)->key_nbr = vet[((div * tm) / dec) - 1];
		algor1_aux(a, b);
		div++;
	}
	if (!ft_checksorted(*a))
		algor(a, b);
	free(vet);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
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
		if (ft_stack_lstsize(a) <= 10)
			algor(&a, &b);
		else if ((ft_stack_lstsize(a) > 10) && (ft_stack_lstsize(a) <= 200))
			algor1(&a, &b, 4);
		else if ((ft_stack_lstsize(a) > 200))
			algor1(&a, &b, 14);
	}
	ft_free(&a);
	return (0);
}
