/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:26:14 by zel-kass          #+#    #+#             */
/*   Updated: 2022/07/06 18:35:46 by zel-kass         ###   ########.fr       */
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
	t_stack	*tmp;
	t_stack	*tmp2;
	
	tmp = *a;
	tmp2 = ft_lstlast(*a);
	if (is_sorted(a))
		return ;
	if (tmp->index > tmp->next->index && tmp->index > tmp2->index)
		rotate_a(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a = ft_get_args(argc, argv);

	get_pos(&a);
	index_stack(&a);
	// printf("%d\n", is_sorted(&a));
	// sort_three(&a);
	ft_print_stack(&a);

	
	return (0);
}
