/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:22:40 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/22 21:43:42 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_median(t_data *a)
{
	int	size;

	size = ft_lstsize(a);
	while (a)
	{
		if (a->index == size / 3)
			return (a->index);
		a = a->next;
	}
	return (0);
}

int	only_little_values(t_data *a, int chunk)
{
	while (a)
	{
		if (a->index > chunk)
			return (0);
		a = a->next;
	}
	return (1);
}

void	pre_sort(t_data **a, t_data **b)
{
	int	low_chunk;
	int	mid_chunk;

	low_chunk = find_median(*a);
	mid_chunk = low_chunk * 2;
	while (!only_little_values(*a, low_chunk))
	{
		if ((*a)->index < low_chunk)
			rotate(a, 'a');
		if ((*a)->index >= low_chunk && (*a)->index <= mid_chunk)
			push_b(a, b);
		else if ((*a)->index > mid_chunk)
		{
			push_b(a, b);
			rotate(b, 'b');
		}
	}
	while (ft_lstsize(*a) > 2)
		push_b(a, b);
}
