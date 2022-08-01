/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:02:05 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/01 21:00:18 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	index_stack(t_data **a)
{
	int		i;
	t_data	*tmp;
	t_data	*tmp2;

	tmp = *a;
	while (tmp)
	{
		i = 0;
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

void	get_pos(t_data **a)
{
	int		pos;
	t_data	*tmp;

	pos = 0;
	tmp = *a;
	while (tmp)
	{
		tmp->pos = pos++;
		tmp = tmp->next;
	}
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
	while ((str[i] > 9 && str[i] < 13) || (str[i] == ' '))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && i < 12)
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (res * sign < -2147483648 || res * sign > 2147483647)
		ft_print_error();
	return (res * sign);
}

void	ft_free_stack(t_data **stack)
{
	int		len;
	t_data	*tmp;

	len = ft_lstsize(*stack);
	while (len >= 0)
	{
		tmp = (*stack)->next;
		free(stack);
		(*stack) = tmp;
		len--;
	}
	free(stack);
}
