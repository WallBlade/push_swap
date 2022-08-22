/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 23:33:38 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/22 17:47:34 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_data **a, t_data **b)
{
	rotate_double(a);
	rotate_double(b);
	ft_putstr("rr\n");
}

void	rrr(t_data **a, t_data **b)
{
	rrotate_double(a);
	rrotate_double(b);
	ft_putstr("rrr\n");
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

void	finish_him(t_data **a)
{
	t_data	*min;

	min = stack_min(*a);
	get_pos(*a);
	set_cost(*a);
	do_op(a, min);
}

int	check_atol(t_data *a)
{
	t_data	*tmp;

	tmp = a;
	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->num == tmp->num)
				return (0);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (1);
}
