/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:24:43 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/09 17:36:12 by zel-kass         ###   ########.fr       */
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

// void	trier_la_plebe(t_data **a, t_data **b)
// {
// 	t_data	*cheap;
// 	t_data	*insert;

// 	if (!*b)
// 		return ;
// 	calculate_cost_b(b);
// 	add_cost_a(a, b);
// 	total_cost(b);
// 	cheap = search_best_cost(b);
// 	printf("cheapest = %d\n", cheap->index);
// 	insert = get_min_costa(a, &cheap);
// 	printf("insert = %d\n", insert->index);
// 	// sort_big(a, b, cheap, insert);
// 	sort_big_a(a, cheap, insert);
// 	ft_print_data(a);
// 	sort_big_b(b, cheap);
// 	ft_print_data(b);
// 	if (cheap->num > (*a)->num)
// 		rotate(a, 'a');
// 	push_a(a, b);
// 	get_pos(a);
// 	get_pos(b);
// 	if (*b)
// 		trier_la_plebe(a, b);
// }

// void	ft_final_finish_him_sort(t_data **a, t_data **b)
// {
// 	t_data	*tmp_a;
// 	int		pos;

// 	trier_la_plebe(a, b);
// 	tmp_a = stack_min(a);
// 	pos = tmp_a->pos;
// 	int size = ft_lstsize(*a);
// 	while (tmp_a->pos != 1 && tmp_a->pos <= size)
// 	{
// 		if (pos < size / 2)
// 		{
// 			rotate(a, 'a');
// 			tmp_a->pos--;
// 		}
// 		else
// 		{
// 			rrotate(a, 'a');
// 			tmp_a->pos++;
// 		}
// 	}
// }

int	main(int argc, char **argv)
{
	t_data	*a;
	t_data	*b;

	a = ft_init_stack(argc, argv);
	b = NULL;
	if (is_sorted(&a))
		return (ft_free_stack(&a), 0);
	if (ft_lstsize(a) >= 2 && ft_lstsize(a) <= 5)
	{
		sort_five(&a, &b);
		return (0);
	}
	// printf("test\n\n");
	// ft_print_data(&a);
	// ft_print_data(&b);
	// printf("before lis\n");
	push_nolis(&a, &b);
	printf("after lis\n");
	get_pos(&b);
	get_pos(&a);
	set_cost(&a);
	set_cost(&b);
	absolute_cost(&a, &b);
	ft_print_data(&a);
	ft_print_data(&b);
	// calculate_cost_b(&b);
	// add_cost_a(&a, &b);
	// for (int i = 0; i < 5; i++)
	// {
	// 	ft_print_data(&a);
	// 	ft_print_data(&b);
	// 	trier_la_plebe(&a, &b);
	// }
	// ft_final_finish_him_sort(&a, &b);
	// get_pos(&a);
	// ft_print_data(&a);
	// printf("is_sorted = %d\n", is_sorted(&a));
	ft_free_stack(&a);
	return (0);
}
