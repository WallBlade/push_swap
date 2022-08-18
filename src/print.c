/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:21:06 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/18 18:15:13 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_data(t_data *a)
{
	int		i;

	i = 0;
	printf("pos\t|\tvalue\t|\tindex\t|\tlis\t|\tis_lis\t|\tcost\t|\tabs\n\n");
	while (i < 90)
	{
		printf("-");
		i++;
	}
	printf("\n");
	while (a)
	{
		printf("%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n", a->pos, a->num, a->index, a->lis, a->is_lis, a->cost, a->abs);
		a = a->next;
	}
}
