/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:19:43 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/23 13:38:59 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

long	ft_atol(char *nptr)
{
	long	i;
	long	signe;
	long	res;

	i = 0;
	res = 0;
	signe = 1;
	while (nptr && (nptr[i] == 32 || nptr[i] == '\t' || nptr[i] == '\n'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		res = res * 10 + (nptr[i] - '0');
		if ((res * signe > INT_MAX) || (res * signe < INT_MIN))
			return (2147483649);
		i++;
	}
	return (res * signe);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	aloc_size(char **av)
{
	int	x;
	int	ret;

	x = 1;
	ret = 0;
	while (av[x])
	{
		ret += ft_strlen(av[x]);
		x++;
	}
	return (ret + x - 2);
}

char	*str_join(char **s1)
{
	char	*str;
	int		i;
	int		y;
	int		j;
	size_t	len;

	i = 1;
	y = 0;
	len = aloc_size(s1);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		j = 0;
		while (s1[i][j])
			str[y++] = s1[i][j++];
		str[y++] = ' ';
		i++;
	}
	str[--y] = '\0';
	return (str);
}

int	*bubble_sort(t_list **stack)
{
	int	*sorted;
	int	step;
	int	i;
	int	tmp;
	int	len;

	len = list_size(*stack);
	sorted = covert_to_arr(stack, list_size(*stack));
	give_value(&step, &i);
	while (step < len - 1)
	{
		i = 0;
		while (i < len - step - 1)
		{
			if (sorted[i] > sorted[i + 1])
			{
				tmp = sorted[i];
				sorted[i] = sorted[i + 1];
				sorted[i + 1] = tmp;
			}
			i++;
		}
		step++;
	}
	return (sorted);
}
