/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:07:12 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/11 19:21:31 by zel-kass         ###   ########.fr       */
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

typedef struct s_global
{
	int				min;
	int				max;
}				t_global;


//------------------	UTILS1	 ------------------//

long	ft_atoi(char *str);
int		ft_countwords(char *str, char c);
char	**ft_split(char *str, char c);
t_data	*ft_lstnew(int nb);
t_data	*ft_lstlast(t_data *a);
void	ft_lstadd_back(t_data **lst, t_data *new);
void	ft_lstadd_front(t_data **lst, t_data *new);
int		ft_lstsize(t_data *lst);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_print_error(void);
void	index_stack(t_data **a);
int		is_sorted(t_data *a);
void	get_pos(t_data *a);
char	**ft_freetab(char **s, int n);
void	absolute_cost(t_data **a, t_data **b);
int		decide_cost(int cost_a, int cost_b);
t_data	*ft_init_stack(int argc, char **argv);
t_data	*ft_catch_errors(int argc, char **params);
int		only_1(t_data **a);
void	set_cost(t_data *stack);

//------------------	UTILS2	 ------------------//

t_data	*stack_min(t_data **a);
t_data	*stack_max(t_data **a);
t_data	*lis_max(t_data **a);
void	find_lis(t_data *a);
void	mark_lis(t_data **a);

//------------------	UTILS3	 ------------------//

void	push_nolis(t_data **a, t_data **b);
void	calculate_cost_b(t_data **b);
void	add_cost_a(t_data **a, t_data **b);
t_data	*get_min_costa(t_data **a, t_data **b);
t_data	*search_best_cost(t_data **b);

//------------------	UTILS4	 ------------------//

void	ft_free_stack(t_data **stack);

//-------------------	 PARSING	 -------------------//

int		ft_treat_args(char **args, int i);
int		ft_check_doubles(char **args, int i);
t_data	*ft_catch_errors(int argc, char **argv);
int		ft_isdigit(char c);

//------------------	OPERATIONS	 ------------------//

void	swap(t_data **stack, char c);
void	push_a(t_data **a, t_data **b);
void	push_b(t_data **a, t_data **b);
void	rotate(t_data **stack, char c);
void	rrotate(t_data **stack, char c);
void	rr(t_data **a, t_data **b);
void	rrr(t_data **a, t_data **b);

//--------------------	   PRINT	 --------------------//

void	ft_print_data(t_data **a);

#endif