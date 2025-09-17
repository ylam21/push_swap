/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:57:07 by omaly             #+#    #+#             */
/*   Updated: 2025/09/17 16:57:35 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*arr_to_list(unsigned int *arr, size_t size)
{
	unsigned int	i;
	int				rank;
	t_list			*head;
	t_list			*new;

	if (!arr)
		return (NULL);
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
