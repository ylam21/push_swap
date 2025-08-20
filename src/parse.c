/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:33:42 by omaly             #+#    #+#             */
/*   Updated: 2025/08/20 18:51:46 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../includes/parse.h"
#include "../includes/utils.h"

t_list *parse(int argc, char **argv)
{
	int i = 1;
	int value = ft_atoi(argv[i]);
	i++;
	t_list *head = ft_lstnew(value);
	t_list *head_copy = head;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		t_list *new = ft_lstnew(value);
		ft_lstadd_back(&head,new);
		i++;
	}
	while (head)
	{
		printf("%d\n",head->d);
		head = head->next;
	}
	printf("Stack A\n\n");
	return head_copy;
}
