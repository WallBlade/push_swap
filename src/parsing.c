/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:45:14 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/18 19:05:52 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_treat_args(char **argv, int i)
{
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_get_args(char **argv, t_data **a)
{
	int	i;

	i = 1;
	if (ft_treat_args(argv, i) == 1)
	{
		while (argv[i])
			ft_lstadd_back(a, ft_lstnew(ft_atol(a, argv[i++])));
	}
	else
		ft_print_error(a);
}

t_data	*ft_init_stack(char **argv, t_data *a)
{
	ft_get_args(argv, &a);
	if (!check_atol(a))
		ft_print_error(&a);
	get_pos(a);
	index_stack(a);
	if (ft_lstsize(a) > 5)
	{
		find_lis(a);
		mark_lis(a);
	}
	return (a);
}
