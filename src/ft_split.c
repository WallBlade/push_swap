/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:47:48 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/08 12:35:04 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_countwords(char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

int	ft_wordlen(char *str, char c, int i)
{
	int	len;

	len = 0;
	while (str[i] && str[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_freetab(char **s, int n)
{
	while (n >= 0)
	{
		free(s[n]);
		n--;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char *str, char c)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	i = 0;
	split = (char **)malloc(sizeof(char *) * (ft_countwords(str, c) + 1));
	if (!split)
		return (NULL);
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		k = 0;
		split[j] = (char *)malloc(sizeof(char) * (ft_wordlen(str, c, i) + 1));
		if (!split[j])
			return (ft_freetab(split, j), NULL);
		while (str[i] && str[i] != c)
			split[j][k++] = str[i++];
		split[j][k] = '\0';
		j++;
	}
	split[j] = 0;
	return (split);
}

void	sort_big(t_data **a, t_data **b, t_data *cheap, t_data *insert)
{
	int	i;

	i = 0;
	while (i < cheap->total)
	{
		while (cheap->pos != 1)
		{
			if (cheap->pos <= (ft_lstsize(*b) / 2))
				rotate(b, 'b');
			else
				rrotate(b, 'b');
			get_pos(b);
			i++;
		}
		if (insert->pos != 1 && insert->pos <= ft_lstsize(*a) / 2)
			rotate(a, 'a');
		else if (insert->pos != 1)
			rrotate(a, 'a');
		get_pos(a);
		i++;
	}
}
