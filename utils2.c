/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:23:23 by zel-kass          #+#    #+#             */
/*   Updated: 2022/07/22 14:49:52 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_max(t_stack **a)
{
	t_stack	*max;
	t_stack	*tmp;
	
	tmp = *a;
	max = *a;
	while (tmp)
	{
		if (tmp->num > max->num)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_stack	*stack_min(t_stack **a)
{
	t_stack	*min;
	t_stack	*tmp;
	
	tmp = *a;
	min = *a;
	while (tmp)
	{
		if (tmp->num < min->num)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void	find_lis(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		save;
	int		i;

	tmp = *a;
	while (tmp)
	{
		i = -1;
		save = tmp->num;
		tmp2 = tmp;
		while (i++ < ft_lstsize(*a))
		{
			if (save < tmp2->num)
			{
				tmp->lis++;
				save = tmp2->num;
			}
			tmp2 = tmp2->next;
			if (tmp2 == NULL)
				tmp2 = *a;
		}
		tmp = tmp->next;
	}
}


t_stack	*lis_max(t_stack **a)
{
	t_stack *tmp;
	t_stack *max;

	tmp = *a;
	max = *a;
	while (tmp)
	{
		if (tmp->lis > max->lis)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

void	mark_lis(t_stack **a)
{
	t_stack	*tmp;
	int		comp;
	int		i;

	i = 0;
	tmp = lis_max(a);
	tmp->is_lis = 1;
	comp = tmp->num;
	while (i < ft_lstsize(*a))
	{
		if (comp < tmp->num)
		{
			tmp->is_lis = 1;
			comp = tmp->num;
		}
		tmp = tmp->next;
		i++;
		if (tmp == NULL)
			tmp = *a;
	}
}

int	only_1(t_stack **a)
{
	t_stack *tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->is_lis == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	push_nolis(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = lis_max(a);
	int median;

	median = ft_lstsize(*a) / 2;
	while (only_1(a))
	{
		if (tmp->is_lis == 0)
		{
			while (tmp->pos != 1)
			{
				if (tmp->pos < (ft_lstsize(*a) / 2))
					rotate_a(a);
				else
					rrotate_a(a);
				get_pos(a);
			}
			push_b(a, b);
			if (tmp->index < median)
				rotate_b(b);
			tmp = lis_max(a);
		}
		get_pos(a);
		tmp = tmp->next;
		if (tmp == NULL)
			tmp = *a;
	}
}

void	calculate_cost_b(t_stack **b)
{
	t_stack	*tmp_b;
	int		count;

	tmp_b = *b;
	while (tmp_b)
	{
		count = 0;
		while (count < tmp_b->pos)
			count++;
		if (tmp_b->pos > (ft_lstsize(*b) / 2))
		{
			count = (ft_lstsize(*b)) - tmp_b->pos;
			tmp_b->cost = count + 1;
		}
		else
			tmp_b->cost = count - 1;
		tmp_b = tmp_b->next;
	}
}

void	add_cost_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_b = *b;
	while (tmp_b)
	{
		tmp_a = *a;
		while (tmp_a)
		{
			if (tmp_a->next && tmp_b &&tmp_a->index < tmp_b->index && tmp_a->next->index > tmp_b->index)
			{
				tmp_b->cost += tmp_a->pos;
				break;
			}
			tmp_a = tmp_a->next;
		}
		tmp_b = tmp_b->next;
	}
}

t_stack		*search_best_cost(t_stack **b)
{
	t_stack	*tmp_b;
	t_stack	*cheap;

	tmp_b = *b;
	cheap = *b;
	while (tmp_b)
	{
		if (cheap->cost > tmp_b->cost)
			cheap = tmp_b;
		tmp_b = tmp_b->next;
	}
	return (cheap);
}

void	index_stack(t_stack **a)
{
	int		i;
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *a;
	while (tmp)
	{
		i = 0;
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	ft_isdigit(char c)
{
	if ((c >= '0' && c <= '9') || (c == '-' || c == '+'))
		return (1);
	return (0);
}

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
