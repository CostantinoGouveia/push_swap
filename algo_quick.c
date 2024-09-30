/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouveia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:47:20 by cgouveia          #+#    #+#             */
/*   Updated: 2024/09/30 12:47:48 by cgouveia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	particiona(long *v, long inicio, long fim)
{
	long	pivo;
	long	temp;

	pivo = (v[inicio] + v[fim] + v[(inicio + fim) / 2]) / 3;
	while (inicio < fim)
	{
		while (inicio < fim && v[inicio] <= pivo)
			inicio++;
		while (inicio < fim && v[fim] > pivo)
			fim--;
		temp = v[inicio];
		v[inicio] = v[fim];
		v[fim] = temp;
	}
	return (inicio);
}

void	quicksort(long *v, long inicio, long fim)
{
	long	pos;

	if (inicio < fim)
	{
		pos = particiona(v, inicio, fim);
		quicksort(v, inicio, pos - 1);
		quicksort(v, pos, fim);
	}
}

long	*fill_vet_pilha(t_stack *a, long *tm)
{
	long	*vet;
	int		i;

	i = 0;
	vet = malloc(sizeof(long) * ft_stack_lstsize(a));
	while (a)
	{
		vet[i] = a->nbr;
		a = a->next;
		i++;
	}
	*tm = i;
	quicksort(vet, 0, i - 1);
	return (vet);
}
