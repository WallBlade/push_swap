/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:43:49 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/08 13:52:53 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_data	*get_min_costa(t_data **a, t_data **b)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_b = *b;
	tmp_a = *a;
	if (tmp_a->index > tmp_b->index && ft_lstlast(*a)->index < tmp_b->index)
		return (tmp_a);
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
		if (cheap->total > tmp_b->total)
			cheap = tmp_b;
		tmp_b = tmp_b->next;
	}
	return (cheap);
}
