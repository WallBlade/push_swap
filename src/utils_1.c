/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:55:45 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/10 18:34:27 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_lis(t_data **a)
{
	t_data	*tmp;
	t_data	*tmp2;
	int		save;
	int		i;

	tmp = *a;
	while (tmp)
	{
		i = 0;
		save = tmp->num;
		tmp2 = tmp;
		while (i < ft_lstsize(*a))
		{
			if (save < tmp2->num)
			{
				tmp->lis++;
				save = tmp2->num;
			}
			tmp2 = tmp2->next;
			if (tmp2 == NULL)
				tmp2 = *a;
			i++;
		}
		tmp = tmp->next;
	}
}

t_data	*lis_max(t_data **a)
{
	t_data	*tmp;
	t_data	*max;

	tmp = *a;
	max = *a;
	while (tmp)
	{
		if (tmp->lis > max->lis)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

void	mark_lis(t_data **a)
{
	t_data	*tmp;
	int		comp;
	int		i;

	i = 0;
	tmp = lis_max(a);
	tmp->is_lis = 1;
	comp = tmp->num;
	while (i < ft_lstsize(*a))
	{
		if (comp < tmp->num)
		{
			tmp->is_lis = 1;
			comp = tmp->num;
		}
		tmp = tmp->next;
		i++;
		if (tmp == NULL)
			tmp = *a;
	}
}

int	only_1(t_data **a)
{
	t_data	*tmp;

	tmp = *a;
	while (tmp)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
	{
		if (tmp->is_lis == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

// void	push_nolis(t_data **a, t_data **b)
// {
// 	t_data	*tmp;
// 	int		median;

// 	tmp = *a;
// 	median = ft_lstsize(*a) / 2;
// 	printf("%d\n", tmp->index);
// 	while (only_1(a))
// 	{
// 		if (tmp->is_lis == 0)
// 		{
// 			printf("num = %d\tpos = %d\tindex = %d\tis_lis = %d\n", tmp->num, tmp->pos, tmp->index, tmp->is_lis);
// 			while (tmp->pos != 1)
// 			{
// 				if (tmp->pos <= (ft_lstsize(*a) / 2))
// 					rotate(a, 'a');
// 				else
// 					rrotate(a, 'a');
// 				get_pos(a);
// 			}
// 			push_b(a, b);
// 			get_pos(a);
// 			break;
// 			if (tmp->index < median)
// 				rotate(b, 'b');
// 		}
// 		get_pos(a);
// 		tmp = tmp->next;
// 		if (tmp == NULL)
// 			tmp = *a;
// 	}
// }

void	do_op(t_data **a, t_data *tmp)
{
	while (tmp->cost > 0)
	{
		rotate(a, 'a');
		tmp->cost--;	
	}
	while (tmp->cost < 0)
	{
		rrotate(a, 'a');
		tmp->cost++;
	}
}

void	push_nolis(t_data **a, t_data **b)
{
	t_data	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->is_lis == 0)
		{
			get_pos(a);
			set_cost(tmp);
			do_op(a, tmp);
			push_b(a, b);
			tmp = *a;
		}
		else
			tmp = tmp->next;
	}
}
