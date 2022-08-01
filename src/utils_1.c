/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:55:45 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/01 12:58:47 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_data	*stack_max(t_data **a)
{
	t_data	*max;
	t_data	*tmp;

	tmp = *a;
	max = *a;
	while (tmp)
	{
		if (tmp->num > max->num)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_data	*stack_min(t_data **a)
{
	t_data	*min;
	t_data	*tmp;

	tmp = *a;
	min = *a;
	while (tmp)
	{
		if (tmp->num < min->num)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void	find_lis(t_data **a)
{
	t_data	*tmp;
	t_data	*tmp2;
	int		save;
	int		i;

	tmp = *a;
	while (tmp)
	{
		i = -1;
		save = tmp->num;
		tmp2 = tmp;
		while (i++ < ft_lstsize(*a))
		{
			if (save < tmp2->num)
			{
				tmp->lis++;
				save = tmp2->num;
			}
			tmp2 = tmp2->next;
			if (tmp2 == NULL)
				tmp2 = *a;
		}
		tmp = tmp->next;
	}
}

t_data	*lis_max(t_data **a)
{
	t_data	*tmp;
	t_data	*max;

	tmp = *a;
	max = *a;
	while (tmp)
	{
		if (tmp->lis > max->lis)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

void	mark_lis(t_data **a)
{
	t_data	*tmp;
	int		comp;
	int		i;

	i = 0;
	tmp = lis_max(a);
	tmp->is_lis = 1;
	comp = tmp->num;
	while (i < ft_lstsize(*a))
	{
		if (comp < tmp->num)
		{
			tmp->is_lis = 1;
			comp = tmp->num;
		}
		tmp = tmp->next;
		i++;
		if (tmp == NULL)
			tmp = *a;
	}
}
