/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:59:52 by omaly             #+#    #+#             */
/*   Updated: 2025/08/28 21:43:55 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int is_digit(int c);
int is_sign(char c);
int is_whitespace(char c);
int ft_atoi(const char *s);
int is_zero(const char *s);
// Other utils for lists
t_list *ft_lstnew(int d);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
int ft_lstsize(t_list *lst);
#endif
