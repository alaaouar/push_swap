/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:31:07 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/22 12:17:44 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int main(int ac, char **av)
{
    t_stack	*a;
	t_stack	*b;
	char	**str;

    b = NULL;
    a = NULL;
    if (ac == 1 || (ac == 2 && av[1][0] == NULL))
        return 1;
    else if (ac == 2)
        av = ft_split(av[1], ' ');
    stack_init(&a, av + 1, ac == 2);
    
    
    
}