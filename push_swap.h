/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:46:19 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/23 12:28:48 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
#define PUSH_SWAP

# include <unistd.h>
# include <stdlib.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_list
{
	int				index;
	int				value;
	struct s_list	*next;
}					t_list;

int			ft_isdigit(int c);
char		**ft_split(char const *s, char c);
char		*str_join(char **s1);
long		ft_atol(const char *nptr);
void		ft_lstclear(t_list **lst);
t_list		*list_new(int val, unsigned int index, t_list *next);
t_list		*list_create(char **target);
int			repeted_number(t_list *list);
int			is_sorted(t_list *lst);
int 		check1_digit(char **str);


#endif