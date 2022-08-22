/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:57:43 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/22 21:03:41 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_data	*get_target(t_data *a, t_data *b)
{
	if (a->index > b->index && ft_lstlast(a)->index < b->index)
		return (a);
	else if (b->index < stack_min(a)->index)
		return (stack_min(a));
	else if (b->index > stack_max(a)->index)
	{
		if (stack_max(a)->next)
			return (stack_max(a)->next);
		return (a);
	}
	while (a)
	{
		if ((a && a->next) && a->index < b->index
			&& a->next->index > b->index)
			return (a->next);
		a = a->next;
	}
	return (NULL);
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
			return (cost_a * -1);
		else
			return (cost_b * -1);
	}
	else if ((cost_a >= 0 && cost_b <= 0) || (cost_a <= 0 && cost_b >= 0))
	{
		if (cost_a < 0)
			cost_a *= -1;
		else if (cost_b < 0)
			cost_b *= -1;
		return (cost_a + cost_b);
	}
	return (0);
}

void	absolute_cost(t_data *a, t_data *b)
{
	t_data	*target;

	while (b)
	{
		target = get_target(a, b);
		b->abs = decide_cost(target->cost, b->cost);
		b = b->next;
	}
}

t_data	*search_best_cost(t_data *b)
{
	t_data	*cheap;

	cheap = b;
	while (b)
	{
		if (cheap->abs > b->abs)
			cheap = b;
		b = b->next;
	}
	return (cheap);
}
