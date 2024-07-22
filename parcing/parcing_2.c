/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:13:30 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/22 12:26:08 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void    node_helper(t_stack **stack, int nbr)
{
    t_stack *node;
    t_stack *last_node;
    
    if (stack == NULL)
        return ;
    node = malloc(sizeof(t_stack));
    if (node == NULL)
        return ;
    node->next = NULL;
    node->content = nbr;
    if (stack == NULL)
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last_node = find_last_node(*stack);
        last_node->next = node;
        node->prev = last_node; 
    }
}

void stack_init(t_stack **a, char *av, bool flag) {
    long nbr;
    char *temp = av; // Use a temporary pointer to iterate

    while (*temp) {
        nbr = ft_atol(temp);
        if (nbr >= 2147483647 || nbr < -2147483648)
            error_free(a, &temp, flag);        
        if (duplicate_error(*a, nbr)) // Corrected pointer dereference
            error_free(a, &temp, flag);
        node_helper(a, nbr); // Corrected pointer usage
        temp++;
    }
    if (flag)
        free_strs(&av); // Assumes av needs to be freed entirely, not just incremented
}
