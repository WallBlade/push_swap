/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:26:14 by zel-kass          #+#    #+#             */
/*   Updated: 2022/07/18 17:24:31 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*max;

	// if (ft_lstsize(*a) > 3)
	// 	ft_print_error();
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

int	main(int argc, char **argv)
{
	t_stack	*a = ft_get_args(argc, argv);
	// t_stack	*tmp;
	t_stack *b;

	b = NULL;
	// a = stack_min(&a);
	// printf("%d\n", a->num);
	get_pos(&a);
	// sort_three(&a);
	// sort_five(&a, &b);
	// push_b(&a, &b);
	// printf("%d\t", a->num);
	// printf("%d\n", b->num);
	index_stack(&a);
	find_lis(&a);
	mark_lis(&a);
	push_nolis(&a, &b);
	ft_print_stack(&a);
	printf("\n");
	get_pos(&b);
	// index_stack(&b);
	ft_print_stack(&b);
	// tmp = lis_max(&a);
	// printf("\n\t\tbiggest lis = %d\n", tmp->num);
	// printf("%d\n", a->lis);

	return (0);
}

ARG=`ruby -e "puts (0..50).to_a.shuffle.join(' ')"`
