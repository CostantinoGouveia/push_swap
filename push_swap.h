#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
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
void		print_stack(t_stack *a);
void		list_args(char **argv, t_stack **stack_a);
void		ft_add_back(t_stack **stack, t_stack *stack_new);
t_stack		*ft_stack_new(int content);
int			check_args(char **argv);
void		alpha_check(char **argv);
int			check_error(char **argv, int i, int j);
int			ft_checkdup(t_stack *a);
int			ft_isalpha(int c);
int			sign(int c);
int			digit(int c);
int			space(int c);
void		ft_error(void);
void		ft_free(t_stack **lst);
t_stack		*ft_stack_lstlast(t_stack *lst);
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
int 		ft_atoi_limit(const char *str);
int			ft_find_index(t_stack *a, int nbr);
int			ft_checksorted(t_stack *stack_a);
void		ft_freestr(char **lst);
t_stack		*ft_process(int argc, char **argv);
t_stack		*ft_sub_process(char **argv);

#endif
