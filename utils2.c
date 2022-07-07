/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:23:23 by zel-kass          #+#    #+#             */
/*   Updated: 2022/07/07 15:08:41 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_max(t_stack **a)
{
	t_stack	*max;
	t_stack	*tmp;
	
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

t_stack	*stack_min(t_stack **a)
{
	t_stack	*min;
	t_stack	*tmp;
	
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
