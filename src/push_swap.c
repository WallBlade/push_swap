/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:24:43 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/02 21:28:06 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_data **a)
{
	t_data	*max;

	max = stack_max(a);
	if (max->pos == 1)
		rotate(a, 'a');
	if (max->pos == 2)
		rrotate(a, 'a');
	if (max->pos == 3)
		swap(a, 'a');
	get_pos(a);
	if (!is_sorted(a))
		sort_three(a);
}

void	sort_five(t_data **a, t_data **b)
{
	t_data	*min;

	while (*a && ft_lstsize(*a) > 3)
	{
		min = stack_min(a);
		while (min->pos != 1)
		{
			if (min->pos > (ft_lstsize(*a) / 2))
				rrotate(a, 'a');
			else
				rotate(a, 'a');
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

void	trier_la_plebe(t_data **a, t_data **b)
{
	t_data	*cheap;
	t_data	*insert;
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
			if (cheap->pos < (ft_lstsize(*b) / 2))
				rotate(b, 'b');
			else
				rrotate(b, 'b');
			get_pos(b);
			i++;
		}
		if (insert->pos != 1 && insert->pos < ft_lstsize(*a) / 2)
			rotate(a, 'a');
		else if (insert->pos != 1)
			rrotate(a, 'a');
		get_pos(a);
		i++;
	}
	if (cheap->num > (*a)->num)
		rotate(a, 'a');
	push_a(a, b);
	get_pos(a);
	get_pos(b);
	if (*b)
		trier_la_plebe(a, b);
}

void	ft_final_finish_him_sort(t_data **a, t_data **b)
{
	t_data	*tmp_a;
	int		pos;

	trier_la_plebe(a, b);
	tmp_a = stack_min(a);
	pos = tmp_a->pos;
	while (tmp_a->pos != 1)
	{
		if (pos < ft_lstsize(*a) / 2)
			rotate(a, 'a');
		else
			rrotate(a, 'a');
		get_pos(a);
	}
}

int	main(int argc, char **argv)
{
	t_data	*a;
	t_data	*b;
	char	**params;

	params = argv;
	a = ft_get_args(argc, params);
	b = NULL;
	get_pos(&a);
	index_stack(&a);
	if (is_sorted(&a))
		return (ft_free_stack(&a), 0);
	if (ft_lstsize(a) >= 2 && ft_lstsize(a) <= 5)
	{
		sort_five(&a, &b);
		// ft_print_data(&a);
		return (0);
	}
	while (!is_sorted(&a))
	{
		find_lis(&a);
		mark_lis(&a);
		push_nolis(&a, &b);
		get_pos(&b);
		ft_final_finish_him_sort(&a, &b);
	}
	// ft_print_data(&a);
	// printf("is_sorted = %d\n", is_sorted(&a));
	ft_free_stack(&a);
	return (0);
}
