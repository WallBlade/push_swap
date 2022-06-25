/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:24:31 by zel-kass          #+#    #+#             */
/*   Updated: 2022/06/25 21:46:21 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;
	
	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] > 9 && str[i] < 13) || (str[i] == ' '))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

int		ft_countwords(char *str, char c)
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

int		ft_wordlen(char *str, char c, int i)
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

// int main(int argc, char **argv)
// {
// 	if (argc < 2)
// 		return (0);
// 	t_stack *a = ft_lstnew(ft_atoi(argv[1]));
// 	printf("%d\n", a->num);
	
// 	return (0);
// }