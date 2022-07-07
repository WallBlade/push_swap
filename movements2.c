/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:05:56 by zel-kass          #+#    #+#             */
/*   Updated: 2022/07/07 16:23:22 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **a)
{
	t_stack	*tmp;

	if (!*a || ft_lstsize(*a) < 2)
		return ;
	tmp = *a;
	*a = (*a)->next;
	ft_lstadd_back(a, tmp);
	tmp->next = NULL;
}

void	rotate_b(t_stack **b)
{
	t_stack	*tmp;

	if (!*b && !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	ft_lstadd_back(b, tmp);
	tmp->next = NULL;
}

void	rrotate_a(t_stack **a)
{
	t_stack	*tmp;

	if (!*a || ft_lstsize(*a) < 2)
		return ;
	tmp = *a;
	while (tmp->next)
	{
		if (tmp->next->next)
			tmp = tmp->next;
		else
			break ;
	}
	ft_lstadd_front(a, tmp->next);
	tmp->next = NULL;
}

void	rrotate_b(t_stack **b)
{
	t_stack	*tmp;

	if (!*b && !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next)
	{
		if (tmp->next->next)
			tmp = tmp->next;
		else
			break ;
	}
	ft_lstadd_front(b, tmp->next);
	tmp->next = NULL;
}
