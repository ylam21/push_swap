/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:33:42 by omaly             #+#    #+#             */
/*   Updated: 2025/09/16 16:53:41 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*build_stack(unsigned int *arr, size_t size)
{
	unsigned int		i;
	int		rank;
	t_list	*head;
	t_list	*new;

	if (!arr)
		return NULL;
	i = 0;
	rank = arr[i];
	i++;
	head = ft_lstnew(rank);
	while (i < size)
	{
		rank = arr[i];
		new = ft_lstnew(rank);
		ft_lstadd_back(&head, new);
		i++;
	}
	return (head);
}

int *parse_args(int argc, char **argv)
{
	if (argc < 1 || !argv)
		return NULL;
	int *res = malloc(sizeof(int) * argc - 1);
	if (!res)
		return NULL;
	int i = 0;
	while (i < argc - 1)
	{
		res[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return res;
}
