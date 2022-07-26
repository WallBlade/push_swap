/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:16:40 by zel-kass          #+#    #+#             */
/*   Updated: 2022/07/22 14:57:13 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack **a)
{
	t_stack	*tmp;
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