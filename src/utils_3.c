/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:00:01 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/15 18:38:33 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_data *a)
{
	while (a->next)
	{
		if (a->index > a->next->index)
			return (0);
		a = a->next;
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

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

long	ft_atoi(char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] > 9 && str[i] < 13) || (str[i] == ' '))
		i++;
	while (str[i] >= '0' && str[i] <= '9' && i < 12)
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (res * sign < -2147483648 || res * sign > 2147483647)
		ft_print_error();
	return (res * sign);
}
