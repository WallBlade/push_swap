/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:00:01 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/08 12:34:39 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	only_1(t_data **a)
{
	t_data	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->is_lis == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	is_sorted(t_data **a)
{
	t_data	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->pos != (tmp->index + 1))
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

int	ft_isdigit(char c)
{
	if ((c >= '0' && c <= '9') || (c == '-' || c == '+'))
		return (1);
	return (0);
}

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
