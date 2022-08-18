/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:07:12 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/18 19:03:02 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_data
{
	int				num;
	int				index;
	int				pos;
	int				lis;
	int				is_lis;
	int				cost;
	int				abs;
	int				total;
	struct s_data	*next;
}				t_data;

//------------------	  LIS	   ------------------//

void	find_lis(t_data *a);
t_data	*lis_max(t_data *a);
void	mark_lis(t_data *a);
void	do_op(t_data **a, t_data *tmp);
void	push_nolis(t_data **a, t_data **b);

//------------------	 COST	  ------------------//

void	set_cost(t_data *stack);
t_data	*get_min_costa(t_data *a, t_data *b);
int		decide_cost(int cost_a, int cost_b);
void	absolute_cost(t_data *a, t_data *b);
t_data	*search_best_cost(t_data *b);

//------------------	UTILS1	 ------------------//

int		is_sorted(t_data *a);
int		ft_strcmp(char *s1, char *s2);
void	ft_print_error(t_data **stack);
void	ft_putstr(char *str);
long	ft_atol(t_data **a, char *str);

//------------------	UTILS2	 ------------------//

t_data	*stack_max(t_data *a);
t_data	*stack_min(t_data *a);
void	index_stack(t_data *a);
void	get_pos(t_data *a);
void	ft_free_stack(t_data **stack);

//------------------	UTILS3	 ------------------//

void	rr(t_data **a, t_data **b);
void	rrr(t_data **a, t_data **b);
void	finish_him(t_data **a);
int		ft_isdigit(char *str);
int		check_atol(t_data *a);

//------------------	 LISTS	  ------------------//

t_data	*ft_lstnew(int nb);
void	ft_lstadd_back(t_data **lst, t_data *new);
void	ft_lstadd_front(t_data **lst, t_data *new);
int		ft_lstsize(t_data *lst);
t_data	*ft_lstlast(t_data *a);

//-------------------	 SPLIT	 -------------------//

int		ft_countwords(char *str, char c);
int		ft_wordlen(char *str, char c, int i);
char	**ft_freetab(char **s, int n);
char	**ft_split(char *str, char c);

//-------------------	 PARSING	 -------------------//

int		ft_check_doubles(char **args, int i);
int		ft_treat_args(char **args, int i);
void	ft_get_args(char **argv, t_data **a);
t_data	*ft_init_stack(char **argv, t_data *a);

//------------------	   ALGO	    ------------------//

void	do_rotate(t_data **stack, int *cost, char c);
void	do_reverse(t_data **stack, int *cost, char c);
void	do_rr(t_data **a, t_data **b, int *cost_a, int *cost_b);
void	do_rrr(t_data **a, t_data **b, int *cost_a, int *cost_b);
void	exec(t_data **a, t_data **b, int cost_a, int cost_b);

//------------------	OPERATIONS	 ------------------//

void	swap(t_data **stack, char c);
void	push_a(t_data **a, t_data **b);
void	push_b(t_data **a, t_data **b);
void	rotate(t_data **stack, char c);
void	rrotate(t_data **stack, char c);
void	rotate_double(t_data **stack);
void	rrotate_double(t_data **stack);

//--------------------	   PRINT	 --------------------//

void	ft_print_data(t_data *a);

#endif