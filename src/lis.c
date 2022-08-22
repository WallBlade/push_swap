/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:55:45 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/22 21:51:43 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_lis(t_data *a)
{
	t_data	*tmp;
	t_data	*tmp2;
	int		save;
	int		i;

	tmp = a;
	while (tmp)
	{
		i = 0;
		save = tmp->num;
		tmp2 = tmp;
		while (i < ft_lstsize(a))
		{
			if (save < tmp2->num)
			{
				tmp->lis++;
				save = tmp2->num;
			}
			tmp2 = tmp2->next;
			if (tmp2 == NULL)
				tmp2 = a;
			i++;
		}
		tmp = tmp->next;
	}
}

t_data	*lis_max(t_data *a)
{
	t_data	*max;

	max = a;
	while (a)
	{
		if (a->lis > max->lis)
			max = a;
		a = a->next;
	}
	return (max);
}

void	mark_lis(t_data *a)
{
	t_data	*tmp;
	int		comp;
	int		i;

	i = 0;
	tmp = lis_max(a);
	tmp->is_lis = 1;
	comp = tmp->num;
	while (i < ft_lstsize(a))
	{
		if (comp < tmp->num)
		{
			tmp->is_lis = 1;
			comp = tmp->num;
		}
		tmp = tmp->next;
		i++;
		if (tmp == NULL)
			tmp = a;
	}
}

void	do_op(t_data **a, t_data *tmp)
{
	while (tmp->cost > 0)
	{
		rotate(a, 'a');
		tmp->cost--;
	}
	while (tmp->cost < 0)
	{
		rrotate(a, 'a');
		tmp->cost++;
	}
}

void	push_nolis(t_data **a, t_data **b)
{
	t_data	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->is_lis == 0)
		{
			get_pos(*a);
			set_cost(*a);
			do_op(a, tmp);
			push_b(a, b);
			tmp = *a;
		}
		else
			tmp = tmp->next;
	}
}
