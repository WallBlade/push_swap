/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:24:43 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/15 18:55:24 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_data **a)
{
	t_data	*max;

	max = stack_max(*a);
	if (max->pos == 0)
		rotate(a, 'a');
	if (max->pos == 1)
		rrotate(a, 'a');
	if (max->pos == 2)
		swap(a, 'a');
	get_pos(*a);
	if (!is_sorted(*a))
		sort_three(a);
}

void	sort_five(t_data **a, t_data **b)
{
	t_data	*min;

	while (*a && ft_lstsize(*a) > 3)
	{
		min = stack_min(*a);
		while (min->pos != 0)
		{
			if (min->pos > (ft_lstsize(*a) / 2))
				rrotate(a, 'a');
			else
				rotate(a, 'a');
			get_pos(*a);
		}
		push_b(a, b);
	}
	index_stack(*a);
	sort_three(a);
	push_a(a, b);
	push_a(a, b);
	get_pos(*a);
}

void	sort_big_stack(t_data **a, t_data **b)
{
	t_data	*cheap;
	t_data	*insert;

	if (!*b)
		return ;
	while (*b)
	{
		get_pos(*a);
		get_pos(*b);
		set_cost(*a);
		set_cost(*b);
		absolute_cost(*a, *b);
		cheap = search_best_cost(*b);
		insert = get_min_costa(*a, cheap);
		exec(a, b, insert->cost, cheap->cost);
		push_a(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_data	*a;
	t_data	*b;

	a = ft_init_stack(argc, argv);
	b = NULL;
	if (is_sorted(a))
		return (ft_free_stack(&a), 0);
	if (ft_lstsize(a) >= 2 && ft_lstsize(a) <= 5)
	{
		sort_five(&a, &b);
		return (ft_free_stack(&a), 0);
	}
	push_nolis(&a, &b);
	sort_big_stack(&a, &b);
	finish_him(&a);
	ft_free_stack(&a);
	return (0);
}
