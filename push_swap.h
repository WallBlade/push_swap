/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:07:12 by zel-kass          #+#    #+#             */
/*   Updated: 2022/06/25 21:59:01 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

// typedef struct	s_big
// {
// 	t_stack	*a;
// 	t_stack	*b;	
// }				t_big;

typedef struct	s_stack
{
	int				num;
	struct s_stack	*next;
}				t_stack;


// UTILS

int		ft_atoi(char *str);
char	**ft_split(char *str, char c);
t_stack	*ft_lstnew(int nb);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);

// PARSING

t_stack	*ft_get_args(int argc, char **argv);

#endif