/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:39:35 by omaly             #+#    #+#             */
/*   Updated: 2025/09/02 10:33:55 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_stack(t_list *stack)
{
	t_list	*prev;
	t_list	*curr;

	prev = stack;
	curr = stack;
	while (prev)
	{
		curr = prev->next;
		free(prev);
		prev = curr;
	}
}
