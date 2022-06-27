/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:27:34 by zel-kass          #+#    #+#             */
/*   Updated: 2022/06/27 20:26:41 by zel-kass         ###   ########.fr       */
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

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = (*a)->next;
	ft_lstadd_front(b, *a);
	*a = tmp;
}

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	
	if (!*a)
		return ;
	tmp = (*b)->next;
	ft_lstadd_front(a, *b);
	*b = tmp;
}

void	rotate_a(t_stack **a)
{
	t_stack	*tmp;
	
	if (!*a && !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	ft_lstadd_back(a, tmp);
	tmp->next = NULL;
}

void	rotate_b(t_stack **b)
{
	t_stack	*tmp;
	
	if (!*b && !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	ft_lstadd_back(b, tmp);
	tmp->next = NULL;
}

void	rrotate_a(t_stack **a)
{
	t_stack	*tmp;
	
	if (!*a && !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next)
	{
		if (tmp->next->next)
			tmp = tmp->next;
		else
			break ;
	}
	ft_lstadd_front(a, tmp->next);
	tmp->next = NULL;
}

void	rrotate_b(t_stack **b)
{
	t_stack	*tmp;

	if (!*b && !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next)
	{
		if (tmp->next->next)
			tmp = tmp->next;
		else
			break ;
	}
	ft_lstadd_front(b, tmp->next);
	tmp->next = NULL;
}

int main(int argc, char **argv)
{
	t_stack *a;
	// t_stack *b;
	
	a = ft_get_args(argc, argv);
	// b = NULL;
	// swap_a(&a);
	// b = ft_lstnew(10);
	// ft_lstadd_back(&b, ft_lstnew(6));
	// push_b(&a, &b);
	// push_b(&a, &b);
	// rotate_a(&a);
	rrotate_a(&a);
	// while (a || b)
	// {
	// 	if (a)
	// 	{
	// 		printf("a = %d	", a->num);
	// 		a = a->next;
	// 	}
	// 	if (b)
	// 	{
	// 		printf("b = %d", b->num);
	// 		b = b->next;
	// 	}
	// 	printf("\n");
	// }
	while (a)
	{
		printf("a = %d\n", a->num);
		a = a->next;
	}
	return (0);
}