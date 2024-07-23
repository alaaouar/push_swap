/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:31:58 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/23 13:32:32 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	check_space(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
        j = 0;
		while (av[i][j] == ' ')
			j++;
		if (!av[i][j])
			error();
		i++;
	}
	return ;
}

int	ft_isdigit(int c)
{
	return (c <= 57 && c >= 48);
}

int check1_digit(char **str)
{
	int i = 0;
	int j;
	while(str[i])
	{
		j = 0;
		if (str[i][j] == '-' || str[i][j] == '+')
			j++;
		while(str[i][j])
		{
			if(!(str[i][j] >= '0' && str[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
void	free_split(char **s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		free(s1[i]);
		i++;
	}
	free(s1);
}
