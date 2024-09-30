/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouveia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:40:17 by cgouveia          #+#    #+#             */
/*   Updated: 2024/09/30 12:42:23 by cgouveia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	long			key_nbr;
	long			tm_aux;
	struct s_stack	*next;
}	t_stack;

long		*fill_vet_pilha(t_stack *a, long *tm);
int			check_args(char **argv);
int			check_error(char **argv, int i, int j);
int			ft_checkdup(t_stack *a);
int			ft_isalpha(int c);
int			sign(int c);
int			digit(int c);
int			space(int c);
int			ft_atoi_limit(const char *str);
int			ft_find_index(t_stack *a, int nbr);
int			ft_checksorted(t_stack *stack_a);
int			ft_stack_lstsize(t_stack *lst);
int			ft_min(t_stack *a);
int			ft_max(t_stack *a);
void		fill_index(t_stack **a);
void		ft_ra(t_stack **a, int j);
void		ft_rb(t_stack **b, int j);
void		ft_sa(t_stack **a, int j);
void		ft_sb(t_stack **b, int j);
void		ft_pa(t_stack **a, t_stack **b, int j);
void		ft_pb(t_stack **a, t_stack **b, int j);
void		ft_rra(t_stack **a, int j);
void		ft_rrb(t_stack **b, int j);
void		ft_ss(t_stack **a, t_stack **b, int j);
void		ft_rr(t_stack **a, t_stack **b, int j);
void		ft_rrr_sub(t_stack **b, int j);
void		ft_rrr(t_stack **a, t_stack **b, int j);
void		ft_freestr(char **lst);
void		aproximacao1(t_stack **b);
void		aproximacao(t_stack **a);
void		ft_error(void);
void		ft_free(t_stack **lst);
void		print_stack(t_stack *a);
void		list_args(char **argv, t_stack **stack_a);
void		ft_add_back(t_stack **stack, t_stack *stack_new);
void		alpha_check(char **argv);
t_stack		*ft_stack_new(int content);
t_stack		*ft_stack_lstlast(t_stack *lst);
t_stack		*ft_process(int argc, char **argv);
t_stack		*ft_sub_process(char **argv);

#endif
