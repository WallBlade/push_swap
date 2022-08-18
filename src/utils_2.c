/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:02:05 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/18 19:38:03 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_data	*stack_max(t_data *a)
{
	t_data	*max;

	max = a;
	while (a)
	{
		if (a->num > max->num)
			max = a;
		a = a->next;
	}
	return (max);
}

t_data	*stack_min(t_data *a)
{
	t_data	*min;

	min = a;
	while (a)
	{
		if (a->num < min->num)
			min = a;
		a = a->next;
	}
	return (min);
}

void	index_stack(t_data *a)
{
	int		i;
	t_data	*tmp;
	t_data	*tmp2;

	tmp = a;
	while (tmp)
	{
		i = 0;
		tmp2 = a;
		while (tmp2)
		{
			if (tmp->num > tmp2->num)
				i++;
			tmp2 = tmp2->next;
		}
		tmp->index = i;
		tmp = tmp->next;
	}
}

void	get_pos(t_data *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a->pos = i;
		i++;
		a = a->next;
	}
}

void	ft_free_stack(t_data **stack)
{
	int		len;
	t_data	*tmp;

	len = ft_lstsize(*stack);
	while (len > 0)
	{
		tmp = (*stack)->next;
		free(*stack);
		(*stack) = tmp;
		len--;
	}
}
