/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:57:43 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/08 14:58:57 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_nolis(t_data **a, t_data **b)
{
	t_data	*tmp;
	int		median;

	tmp = lis_max(a);
	median = ft_lstsize(*a) / 2;
	// printf("%d\n", tmp->index);
	while (only_1(a))
	{
		if (tmp->is_lis == 0)
		{
			while (tmp->pos != 1)
			{
				if (tmp->pos <= (ft_lstsize(*a) / 2))
					rotate(a, 'a');
				else
					rrotate(a, 'a');
				get_pos(a);
			}
			push_b(a, b);
			if (tmp->index < median)
				rotate(b, 'b');
		}
		get_pos(a);
		tmp = tmp->next;
		if (tmp == NULL)
			tmp = *a;
	}
}

void	calculate_cost_b(t_data **b)
{
	t_data	*tmp_b;
	int		count;
	int		len;

	tmp_b = *b;
	len = ft_lstsize(*b);
	while (tmp_b)
	{
		count = 0;
		while (count < tmp_b->pos)
			count++;
		if (tmp_b->pos > len / 2 + 1)
			tmp_b->cost_b = len - tmp_b->pos + 1;
		else
			tmp_b->cost_b = count - 1;
		tmp_b = tmp_b->next;
	}
}

void	add_cost_a(t_data **a, t_data **b)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_b = *b;
	tmp_a = *a;
	if (tmp_a->index > tmp_b->index && ft_lstlast(*a)->index < tmp_b->index)
		tmp_b->cost_a = 0;
	while (tmp_b)
	{
		tmp_a = (*a)->next;
		while (tmp_a)
		{
			if ((tmp_a && tmp_a->next) && tmp_a->index < tmp_b->index
				&& tmp_a->next->index > tmp_b->index)
				decide_cost(a, tmp_a, tmp_b);
			else if (tmp_b->index < stack_min(a)->index)
				decide_cost(a, stack_min(a), tmp_b);
			else if (tmp_b->index > stack_max(a)->index)
				decide_cost(a, stack_max(a), tmp_b);
			else if (tmp_a->next == NULL)
			{
				if (tmp_a->index < tmp_b->index && (*a)->index > tmp_b->index)
					tmp_b->cost_a = 0;
			}
			tmp_a = tmp_a->next;
		}
		tmp_b = tmp_b->next;
	}
}
void	decide_cost(t_data **a, t_data *tmp_a, t_data *tmp_b)
{
	if (tmp_a->pos < ft_lstsize(*a) / 2)
		tmp_b->cost_a = tmp_a->pos;
	else
		tmp_b->cost_a = ft_lstsize(*a) - tmp_a->pos + 1;
}


void	total_cost(t_data **b)
{
	t_data	*tmp_b;

	tmp_b = *b;
	while (tmp_b)
	{
		tmp_b->total = tmp_b->cost_a + tmp_b->cost_b;
		tmp_b = tmp_b->next;
	}
}
