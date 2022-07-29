/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:26:14 by zel-kass          #+#    #+#             */
/*   Updated: 2022/07/28 19:08:44 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	get_pos(a);
}

void	trier_la_plebe(t_stack **a, t_stack **b)
{
	t_stack	*cheap;
	t_stack	*insert;
	int		i;
	
	i = 0;
	calculate_cost_b(b);
	add_cost_a(a, b);
	cheap = search_best_cost(b);
	insert = get_min_costa(a, &cheap);
	while (i < cheap->cost)
	{
		while (cheap->pos != 1)
		{
			if (cheap->pos <  (ft_lstsize(*b) / 2))
				rotate_b(b);
			else
				rrotate_b(b);
			get_pos(b);
			i++;
		}
		if (insert->pos != 1 && insert->pos < ft_lstsize(*a) / 2)
			rotate_a(a);
		else if (insert->pos != 1)
			rrotate_a(a);
		get_pos(a);
		i++;
	}
	if (cheap->num > (*a)->num)
		rotate_a(a);
	push_a(a, b);
	get_pos(a);
	get_pos(b);
	if (*b)
		trier_la_plebe(a, b);
}

void	ft_final_finish_him_sort(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	int		pos;
	
	trier_la_plebe(a, b);
	tmp_a = stack_min(a);
	pos = tmp_a->pos;
	while (tmp_a->pos != 1)
	{
		if (pos < ft_lstsize(*a) / 2)
			rotate_a(a);
		else
			rrotate_a(a);
		get_pos(a);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a = ft_get_args(argc, argv);
	t_stack *b;

	b = NULL;
	get_pos(&a);
	index_stack(&a);
	find_lis(&a);
	mark_lis(&a);
	push_nolis(&a, &b);
	get_pos(&b);
	ft_final_finish_him_sort(&a, &b);
	ft_print_stack(&a);
	printf("\n");

	return (0);
}
