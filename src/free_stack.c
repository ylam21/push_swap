/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:39:35 by omaly             #+#    #+#             */
/*   Updated: 2025/09/01 16:42:32 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void free_stack(t_list *stack)
{
	t_list *prev = stack;
	t_list *curr = stack;
	while (prev)
	{
		curr = prev->next;
		free(prev);
		prev = curr;
	}
}
