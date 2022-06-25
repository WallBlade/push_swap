/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:27:34 by zel-kass          #+#    #+#             */
/*   Updated: 2022/06/25 22:15:52 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *a)
{
	int	tmp;

	tmp = a->num;
	a->num = a->next->num;
	a->next->num = tmp;
}

void	swap_b(t_stack *b)
{
	int	tmp;

	tmp = b->num;
	b->num = b->next->num;
	b->next->num = tmp;
}

void	push_b(t_stack *a, t_stack *b)
{
	ft_lstadd_front(&b, ft_lstnew(a->num));
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	
	a = ft_get_args(argc, argv);
	b = ft_lstnew(10);
	ft_lstadd_back(&b, ft_lstnew(6));
	push_b(a, b);
	while (a || b)
	{
		printf("%d	%d\n", a->num, b->num);
		a = a->next;
		b = b->next;
	}
	
	return (0);
}