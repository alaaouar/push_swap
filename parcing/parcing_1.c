/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:06:14 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/22 12:20:28 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**free_strs(char **strs)
{
	unsigned int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

// int	ft_strlen(char **str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

void	helper_func(const char *str, int *index, int *sign)
{
	while (str[*index] == ' '
		|| (str[*index] >= '\t' && str[*index] <= '\r'))
		(*index)++;
	if (str[*index] == '-'
		&& (str[*index + 1] >= '0' && str[*index + 1] <= '9'))
	{
		(*sign) *= -1;
		(*index)++;
	}
	if (str[*index] == '+'
		&& (str[*index + 1] >= '0' && str[*index + 1] <= '9'))
		(*index)++;
}

long long	ft_atol(char *str)
{
	int			index;
	long long	results;
	int			sign;

	index = 0;
	results = 0;
	sign = 1;
	helper_func(str, &index, &sign);
	while (str[index])
	{
		if (str[index] >= '0' && str[index] <= '9')
			results = (results * 10) + (str[index] - '0');
		else
			break ;
		if ((results > 2147483648 && sign == -1)
			|| (results > 2147483647 && sign == 1))
			return (results * sign);
		index++;
	}
	return (results * sign);
}
