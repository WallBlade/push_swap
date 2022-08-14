/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:11:00 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/14 23:09:50 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	do_rotate(t_data **stack, int *cost, char c)
{
	while (*cost > 0)
	{
		rotate(stack, c);
		(*cost)--;	
	}
}

void	do_reverse(t_data **stack, int *cost, char c)
{
	while (*cost < 0)
	{
		rrotate(stack, c);
		(*cost)++;
	}
}

void	do_rr(t_data **a, t_data **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 || *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;	
		(*cost_b)--;	
	}
}

void	do_rrr(t_data **a, t_data **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 || *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;	
		(*cost_b)++;	
	}
}

void	exec(t_data **a, t_data **b, int cost_a, int cost_b)
{
	while (cost_a != 0 || cost_b != 0)
	{
		if (cost_a > 0 && cost_b <= 0)
			do_rotate(a, &cost_a, 'a');
		else if (cost_b > 0 && cost_a <= 0)
			do_rotate(b, &cost_b, 'b');
		else if (cost_a < 0 && cost_b >= 0)
			do_reverse(a, &cost_a, 'a');
		else if (cost_b < 0 && cost_a >= 0)
			do_reverse(b, &cost_b, 'b');
		else if (cost_a > 0 && cost_b > 0)
			do_rr(a, b, &cost_a, &cost_b);
		else if (cost_a < 0 && cost_b < 0)
			do_rrr(a, b, &cost_a, &cost_b);
	}
}
