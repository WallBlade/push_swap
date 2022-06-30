/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 21:45:47 by zel-kass          #+#    #+#             */
/*   Updated: 2022/06/30 13:09:42 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*ft_lstnew(int nb)
{
	t_stack	*a;
	
	a = malloc(sizeof(t_stack *) * 1);
	if (!a)
		return (NULL);
	a->num = nb;
	a->next = NULL;
	return (a); 
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack *tmp;

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

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstdelone(t_stack *lst)
{
	free(lst);
}

int		ft_lstsize(t_stack *lst)
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