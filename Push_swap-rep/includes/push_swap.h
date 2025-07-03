/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunogue <brunogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:09:15 by brunogue          #+#    #+#             */
/*   Updated: 2025/04/02 17:56:27 by brunogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*ft_stack_new(int content);

//OPERATIONS
void	ft_pa(t_stack **a, t_stack **b, int i);
void	ft_pb(t_stack **a, t_stack **b, int i);
void	ft_ra(t_stack **a, int i);
void	ft_rb(t_stack **b, int i);
void	ft_rr(t_stack **a, t_stack **b, int i);
//OPERATIONS2
void	ft_sa(t_stack **a, int i);
void	ft_sb(t_stack **b, int i);
void	ft_ss(t_stack **a, t_stack **b, int i);
//OPERATIONS3
void	ft_rra(t_stack **a, int i);
void	ft_rrb(t_stack **b, int i);
void	ft_rrr(t_stack **a, t_stack **b, int i);
void	ft_rrr_cont(t_stack **b, int i);

//SORT
t_stack	**ft_sort_a(t_stack **a, t_stack **b);
t_stack	*ft_sort_b(t_stack **a);
void	ft_sort(t_stack **a);
void	ft_sort_b_3(t_stack **a, t_stack **b);
void	ft_sort_three(t_stack **a);

//PROCESS
t_stack	*ft_process(int ac, char **av);
t_stack	*ft_subprocess(char **av);

//ERRORS
void	ft_error_digit(void);
void	ft_error_limit_numbers(void);
void	ft_error_arg(void);
void	ft_error_stack_dup(void);
void	ft_error_memory(void);

//CHECKS
int		ft_checkdup(t_stack *a);
int		ft_checksorted(t_stack *a);
int		checkargs_syntax(char **av, int i, int x);
void	checkalpha(char **av);
int		checkargs(char **argv);

//FREE&PARSE
void	ft_free(t_stack **lst);
void	ft_free_str(char **lst);
void	ft_list_args(char **av, t_stack **a);
t_stack	*ft_parse_args_quoted(char **av);
t_stack	*ft_parse(int ac, char **av);

//ROTATIONS_CASES
int		ft_rarb(t_stack *a, t_stack *b, int c);
int		ft_rrarrb(t_stack *a, t_stack *b, int c);
int		ft_rrarb(t_stack *a, t_stack *b, int c);
int		ft_rarrb(t_stack *a, t_stack *b, int c);

//ROTATIONS_CASES2
int		ft_rarb_a(t_stack *a, t_stack *b, int c);
int		ft_rrarrb_a(t_stack *a, t_stack *b, int c);
int		ft_rarrb_a(t_stack *a, t_stack *b, int c);
int		ft_rrarb_a(t_stack *a, t_stack *b, int c);

//ROTATE_APPLY
int		ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s);
int		ft_apply_rarb(t_stack **a, t_stack **b, int c, char s);
int		ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char s);
int		ft_apply_rrarb(t_stack **a, t_stack **b, int c, char s);
int		ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s);

//ROTATE_TYPE
int		ft_rarb_a(t_stack *a, t_stack *b, int c);
int		ft_rotate_type_ba(t_stack *a, t_stack *b);
int		ft_rotate_type_ab(t_stack *a, t_stack *b);

//STACK_POSITIONING
int		ft_find_index(t_stack *a, int nbr);
int		ft_find_node_a(t_stack *a, int push_number);
int		ft_find_node_b(t_stack *b, int push_number);
void	ft_add_back(t_stack **stack, t_stack *stack_new);

//UTILS
int		ft_atoi2(const char *str);
t_stack	*ft_stack_last(t_stack *lst);
int		ft_stack_size(t_stack *lst);
int		ft_min_number(t_stack *a);
int		ft_max_number(t_stack *a);
//UTILS_CHECKS
int		sign(int c);
int		digit(int c);
int		space(int c);

#endif