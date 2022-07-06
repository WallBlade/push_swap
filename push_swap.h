/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:07:12 by zel-kass          #+#    #+#             */
/*   Updated: 2022/07/06 17:28:55 by zel-kass         ###   ########.fr       */
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
	struct s_stack	*next;
}				t_stack;

// UTILS

long	ft_atoi(char *str);
char	**ft_split(char *str, char c);
t_stack	*ft_lstnew(int nb);
t_stack	*ft_lstlast(t_stack *a);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_print_error(void);
void	index_stack(t_stack **a);
void	get_pos(t_stack **a);


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