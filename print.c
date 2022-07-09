/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:16:40 by zel-kass          #+#    #+#             */
/*   Updated: 2022/07/09 17:53:48 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	printf("pos\t|\tvalue\t|\tindex\t|\tlis\t|\tis_lis\n\n");
	printf("---------------------------------------------------------\n\n");
	while (tmp)
	{
		printf("%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n", tmp->pos, tmp->num, tmp->index, tmp->lis, 5);
		tmp = tmp->next;
	}
}