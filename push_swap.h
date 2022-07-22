/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:07:12 by zel-kass          #+#    #+#             */
/*   Updated: 2022/07/22 12:36:48 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

// typedef struct	s_big
// {
// 	t_stack	*a;
// 	t_stack	*b;	
// }				t_big;

typedef struct s_stack
{
	int				num;
	int				index;
	int				pos;
	int				lis;
	int				is_lis;
	int				cost;
	struct s_stack	*next;
}				t_stack;

// UTILS

long	ft_atoi(char *str);
char	**ft_split(char *str, char c);
t_stack	*ft_lstnew(int nb);
t_stack	*ft_lstlast(t_stack *a);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*stack_min(t_stack **a);
t_stack	*stack_max(t_stack **a);
t_stack	*lis_max(t_stack **a);
void	mark_lis(t_stack **a);
int		ft_lstsize(t_stack *lst);
void	ft_putstr(char *str);
int		ft_isdigit(char c);
int		ft_strcmp(char *s1, char *s2);
void	find_lis(t_stack **a);
void	push_nolis(t_stack **a, t_stack **b);
void	ft_print_error(void);
void	index_stack(t_stack **a);
int		is_sorted(t_stack **a);
void	get_pos(t_stack **a);
void	calculate_cost_b(t_stack **b);
t_stack	*search_best_cost(t_stack **b);
void	add_cost_a(t_stack **a, t_stack **b);

//	PARSING

int		ft_treat_args(char **args, int i);
int		ft_check_doubles(char **args, int i);
t_stack	*ft_get_args(int argc, char **argv);

//	MOUV's

void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	push_a(t_stack **a, t_stack **b);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rrotate_a(t_stack **a);
void	rrotate_b(t_stack **b);

//	PRINT

void	ft_print_stack(t_stack **a);

#endif