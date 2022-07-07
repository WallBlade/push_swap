/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:26:14 by zel-kass          #+#    #+#             */
/*   Updated: 2022/07/07 17:40:17 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack **a)
{
	int		i;
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *a;
	while (tmp)
	{
		i = 1;
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

void	get_pos(t_stack **a)
{
	int		pos;
	t_stack	*tmp;

	pos = 1;
	tmp = *a;
	while (tmp)
	{
		tmp->pos = pos++;
		tmp = tmp->next;
	}
}

int		is_sorted(t_stack **a)
{
	t_stack	*tmp;
	
	tmp = *a;
	while (tmp)
	{
		if (tmp->pos != tmp->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_three(t_stack **a)
{
	t_stack	*max;
	
	max = stack_max(a);
	if (max->pos == 1)
		rotate_a(a);
	if (max->pos == 2)
		rrotate_a(a);
	if (max->pos == 3)
		swap_a(a);
	get_pos(a);
	if (!is_sorted(a))
		sort_three(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*min;

	while (*a && ft_lstsize(*a) > 3)
	{
		min = stack_min(a);
		while (min->pos != 1)
		{
			if (min->pos > (ft_lstsize(*a) / 2))
				rrotate_a(a);
			else
				rotate_a(a);
			get_pos(a);
		}
		push_b(a, b);
	}
	index_stack(a);
	sort_three(a);
	push_a(a, b);
	push_a(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a = ft_get_args(argc, argv);
	t_stack *b;

	b = NULL;
	// a = stack_min(&a);
	// printf("%d\n", a->num);
	// sort_three(&a);
	sort_five(&a, &b);
	index_stack(&a);
	// push_b(&a, &b);
	// printf("%d\t", a->num);
	// printf("%d\n", b->num);
	ft_print_stack(&a);

	
	return (0);
}
