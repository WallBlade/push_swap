/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:44:09 by zel-kass          #+#    #+#             */
/*   Updated: 2022/07/05 18:42:17 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (args[i][j] < '0' || args[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_stack	*ft_get_args(int argc, char **argv)
{
	int		i;
	t_stack	*a;

	i = 1;
	a = NULL;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = 0;
	}
	if (ft_treat_args(argv, i) == 1)
	{
		while (argv[i])
			ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i++])));
	}
	else
		ft_print_error();
	return (a);
}

// int main(int argc, char **argv)
// {
// 	t_stack	*a = ft_get_args(argc, argv);

// 	while (a)
// 	{
// 		printf("%d\n", a->num);
// 		a = a->next;
// 	}
	// int i = 1;

	// if (argc == 2)
	// {
	// 	argv = ft_split(argv[1], ' ');
	// 	i = 0;
	// }
	// printf("%d\n", ft_treat_args(argv, i));
// 	return (0);
// }