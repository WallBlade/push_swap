/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 23:33:38 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/14 23:59:59 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	finish_him(t_data **a)
{
	t_data	*min;

	min = stack_min(*a);
	get_pos(*a);
	set_cost(*a);
	do_op(a, min);
}

int	ft_isdigit(char c)
{
	if ((c >= '0' && c <= '9') || (c == '-' || c == '+'))
		return (1);
	return (0);
}
