/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:45:14 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/01 20:38:58 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_doubles(char **args, int i)
{
	int	j;

	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_strcmp(args[i], args[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_treat_args(char **args, int i)
{
	int	j;

	if (!ft_check_doubles(args, i))
		return (0);
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				return (0);
			if (args[i][j] == '-')
				j++;
			j++;
		}
		i++;
	}
	return (1);
}

t_data	*ft_get_args(int argc, char **argv)
{
	int		i;
	char	**params;
	t_data	*a;

	i = 1;
	params = argv;
	a = NULL;
	if (argc == 2 && ft_countwords(argv[1], ' ') < 2)
		exit (EXIT_FAILURE);
	if (argc == 2)
	{
		params = ft_split(argv[1], ' ');
		i = 0;
	}
	if (ft_treat_args(params, i) == 1)
	{
		while (params[i])
			ft_lstadd_back(&a, ft_lstnew(ft_atoi(params[i++])));
	}
	else
	{
		if (argc == 2)
			ft_freetab(params, ft_countwords(argv[1], ' '));
		ft_print_error();
	}
	if (argc == 2)
		ft_freetab(params, ft_countwords(argv[1], ' '));
	return (a);
}
