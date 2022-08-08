/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:02:47 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/08 14:42:39 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_data **stack, char c)
{
	t_data	*tmp;

	if (!*stack && !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	if (c == 'a')
		printf("sa\n");
	else
		printf("sb\n");
}

void	push_a(t_data **a, t_data **b)
{
	t_data	*tmp;

	if (*b == NULL)
		return ;
	tmp = (*b)->next;
	ft_lstadd_front(a, *b);
	*b = tmp;
	printf("pa\n");
}

void	push_b(t_data **a, t_data **b)
{
	t_data	*tmp;

	if (*a == NULL)
		return ;
	tmp = (*a)->next;
	ft_lstadd_front(b, *a);
	*a = tmp;
	printf("pb\n");
}
