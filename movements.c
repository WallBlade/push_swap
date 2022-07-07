/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:27:34 by zel-kass          #+#    #+#             */
/*   Updated: 2022/07/07 16:02:04 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **a)
{
	t_stack	*tmp;

	if (!*a && !(*a)->next)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
}

void	swap_b(t_stack **b)
{
	t_stack	*tmp;

	if (!*b && !(*b)->next)
		return ;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = *b;
	*b = tmp;
}

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*b == NULL)
		return ;
	tmp = (*b)->next;
	ft_lstadd_front(a, *b);
	*b = tmp;
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a == NULL)
		return ;
	tmp = (*a)->next;
	ft_lstadd_front(b, *a);
	*a = tmp;
}

// int main(int argc, char **argv)
// {
// 	t_stack *a;
// 	t_stack *b;

// 	a = ft_get_args(argc, argv);
// 	// b = NULL;
// 	// swap_a(&a);
// 	b = ft_lstnew(10);
// 	// ft_lstadd_back(&b, ft_lstnew(6));
// 	push_b(&a, &b);
// 	push_b(&a, &b);
// 	// rotate_a(&a);
// 	// rrotate_a(&a);
// 	while (a || b)
// 	{
// 		if (a)
// 		{
// 			printf("a = %d	", a->num);
// 			a = a->next;
// 		}
// 		if (b)
// 		{
// 			printf("b = %d", b->num);
// 			b = b->next;
// 		}
// 		printf("\n");
// 	}
// 	// while (a)
// 	// {
// 	// 	printf("a = %d\n", a->num);
// 	// 	a = a->next;
// 	// }
// 	return (0);
// }