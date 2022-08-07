/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:41:14 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/05 17:10:41 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_data	*ft_lstnew(int nb)
{
	t_data	*stack;

	stack = malloc(sizeof(*stack) * 1);
	if (!stack)
		return (NULL);
	stack->num = nb;
	stack->index = 0;
	stack->pos = 1;
	stack->lis = 0;
	stack->is_lis = 0;
	stack->cost_a = 0;
	stack->cost_b = 0;
	stack->total = 0;
	stack->next = NULL;
	return (stack);
}

void	ft_lstadd_back(t_data **lst, t_data *new)
{
	t_data	*tmp;

	tmp = *lst;
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_lstadd_front(t_data **lst, t_data *new)
{
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_data *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_data	*ft_lstlast(t_data *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}
