/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:44:09 by zel-kass          #+#    #+#             */
/*   Updated: 2022/06/25 21:06:59 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_get_args(int argc, char **argv)
{
	int	i;
	t_stack	*a;		
	
	i = 1;
	a = NULL;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = 0;
	}
	while (argv[i])
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i++])));
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

// 	return (0);
// }