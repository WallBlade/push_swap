/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:03:29 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/08 14:42:57 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_data **stack, char c)
{
	t_data	*tmp;

	if (!*stack || ft_lstsize(*stack) < 2)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	ft_lstadd_back(stack, tmp);
	tmp->next = NULL;
	if (c == 'a')
		printf("ra\n");
	else
		printf("rb\n");
}

void	rrotate(t_data **stack, char c)
{
	t_data	*tmp;

	if (!*stack || ft_lstsize(*stack) < 2)
		return ;
	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->next->next)
			tmp = tmp->next;
		else
			break ;
	}
	ft_lstadd_front(stack, tmp->next);
	tmp->next = NULL;
	if (c == 'a')
		printf("rra\n");
	else
		printf("rrb\n");
}

void	rr(t_data **a, t_data **b)
{
	rotate(a, 'a');
	rotate(b, 'b');
}

void	rrr(t_data **a, t_data **b)
{
	rrotate(a, 'a');
	rrotate(b, 'b');
}
