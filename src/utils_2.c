/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:57:43 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/11 17:20:53 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_cost(t_data *stack)
{
	int		size;

	size = ft_lstsize(stack);
	while (stack)
	{
		if (stack->pos <= size / 2)
			stack->cost = stack->pos;
		else
			stack->cost = stack->pos - size;
		stack = stack->next;
	}
}

int	decide_cost(int cost_a, int cost_b)
{
	if (cost_a >= 0 && cost_b >= 0)
	{
		if (cost_a > cost_b)
			return (cost_a);
		else
			return (cost_b);
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		if (cost_a < cost_b)
			return (cost_a * - 1);
		else
			return (cost_b * - 1);
	}
	else if ((cost_a >= 0 && cost_b <= 0) || (cost_a <= 0 && cost_b >= 0))
	{
		if (cost_a < 0)
			cost_a *= - 1;
		else if (cost_b < 0)
			cost_b *= - 1;
		return (cost_a + cost_b);
	}
	return (0);
}

void	absolute_cost(t_data **a, t_data **b)
{
	t_data	*tmp_b;
	t_data	*insert;
	
	tmp_b = *b;
	while (tmp_b)
	{
		insert = get_min_costa(a, &tmp_b);
		tmp_b->abs = decide_cost(insert->cost, tmp_b->cost);
		tmp_b = tmp_b->next;
	}
}
