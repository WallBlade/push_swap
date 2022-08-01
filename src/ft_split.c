/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:47:48 by zel-kass          #+#    #+#             */
/*   Updated: 2022/08/01 12:49:10 by zel-kass         ###   ########.fr       */
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
			return (NULL);
		while (str[i] && str[i] != c)
			split[j][k++] = str[i++];
		split[j][k] = '\0';
		j++;
	}
	split[j] = 0;
	return (split);
}
