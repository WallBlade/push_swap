/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:23:23 by zel-kass          #+#    #+#             */
/*   Updated: 2022/07/08 14:31:54 by zel-kass         ###   ########.fr       */
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

void	index_stack(t_stack **a)
{
	int		i;
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *a;
	while (tmp)
	{
		i = 1;
		tmp2 = *a;
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

void	get_pos(t_stack **a)
{
	int		pos;
	t_stack	*tmp;

	pos = 1;
	tmp = *a;
	while (tmp)
	{
		tmp->pos = pos++;
		tmp = tmp->next;
	}
}

int		is_sorted(t_stack **a)
{
	t_stack	*tmp;
	
	tmp = *a;
	while (tmp)
	{
		if (tmp->pos != tmp->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
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
