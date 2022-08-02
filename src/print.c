/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:21:06 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/01 13:22:38 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_data(t_data **a)
{
	t_data	*tmp;
	int		i;
	
	tmp = *a;
	i = 0;
	printf("pos\t|\tvalue\t|\tindex\t|\tlis\t|\tis_lis\t|\tcost\n\n");
	while (i < 100)
	{
		printf("-");
		i++;
	}
		printf("\n");
	while (tmp)
	{
		printf("%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n", tmp->pos, tmp->num, tmp->index, tmp->lis, tmp->is_lis, tmp->cost);
		tmp = tmp->next;
	}
}