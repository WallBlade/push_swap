/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:57:43 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/01 21:52:13 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_nolis(t_data **a, t_data **b)
{
	t_data	*tmp;
	int		median;

	tmp = lis_max(a);
	median = ft_lstsize(*a) / 2;
	while (only_1(a))
	{
		if (tmp->is_lis == 0)
		{
			while (tmp->pos != 1)
			{
				if (tmp->pos < (ft_lstsize(*a) / 2))
					rotate(a);
				else
					rrotate(a);
				get_pos(a);
			}
			push_b(a, b);
			if (tmp->index < median)
				rotate(b);
			tmp = lis_max(a);
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

	tmp_b = *b;
	while (tmp_b)
	{
		count = 0;
		while (count < tmp_b->pos)
			count++;
		if (tmp_b->pos > (ft_lstsize(*b) / 2))
		{
			count = (ft_lstsize(*b)) - tmp_b->pos;
			tmp_b->cost = count + 1;
		}
		else
			tmp_b->cost = count - 1;
		tmp_b = tmp_b->next;
	}
}

void	add_cost_a(t_data **a, t_data **b)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_b = *b;
	while (tmp_b)
	{
		tmp_a = *a;
		while (tmp_a)
		{
			if ((tmp_a && tmp_a->next) && tmp_a->index < tmp_b->index
				&& tmp_a->next->index > tmp_b->index)
			{
				tmp_b->cost += tmp_a->pos;
				break ;
			}
			else if (tmp_b->index < stack_min(a)->index)
			{
				tmp_b->cost += stack_min(a)->pos - 1;
				break ;
			}
			else if (tmp_b->index > stack_max(a)->index)
			{
				tmp_b->cost += stack_max(a)->pos - 1;
				break ;
			}
			else if (tmp_a->next == NULL)
			{
				if (tmp_a->index < tmp_b->index && (*a)->index > tmp_b->index)
					tmp_b->cost += 1;
			}
			tmp_a = tmp_a->next;
		}
		tmp_b = tmp_b->next;
	}
}

t_data	*get_min_costa(t_data **a, t_data **b)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_b = *b;
	while (tmp_b)
	{
		tmp_a = *a;
		while (tmp_a)
		{
			if ((tmp_a && tmp_a->next) && tmp_a->index < tmp_b->index
				&& tmp_a->next->index > tmp_b->index)
				return (tmp_a);
			else if (tmp_b->index < stack_min(a)->index)
				return (stack_min(a));
			else if (tmp_b->index > stack_max(a)->index)
				return (stack_max(a));
			else if (tmp_a->next == NULL)
			{
				if (tmp_a->index < tmp_b->index && (*a)->index > tmp_b->index)
					return (*a);
			}
			tmp_a = tmp_a->next;
		}
		tmp_b = tmp_b->next;
	}
	return (NULL);
}

t_data	*search_best_cost(t_data **b)
{
	t_data	*tmp_b;
	t_data	*cheap;

	tmp_b = *b;
	cheap = *b;
	while (tmp_b)
	{
		if (cheap->cost > tmp_b->cost)
			cheap = tmp_b;
		tmp_b = tmp_b->next;
	}
	return (cheap);
}
