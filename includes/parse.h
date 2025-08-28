/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:33:31 by omaly             #+#    #+#             */
/*   Updated: 2025/08/28 14:52:51 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
#define PARSE_H

#include <stdlib.h>

typedef struct s_list
{
	int d;
	struct s_list *next;
} t_list;

// TODO: move to different header
void swap(t_list **list);
void push(t_list **stack_a, t_list **stack_b);
// newl
t_list *parse(int argc, char **argv);
// Other utils for lists
t_list *ft_lstnew(int d);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
int ft_lstsize(t_list *lst);
#endif
