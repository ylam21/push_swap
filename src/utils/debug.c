/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:14:59 by omaly             #+#    #+#             */
/*   Updated: 2025/09/16 15:22:07 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_stack(t_list *stack)
{
	t_list	*curr;

	if (!stack)
	{
		printf("NULL\n");
		return ;
	}
	curr = stack;
	while (curr)
	{
		printf("%d ", curr->rank);
		curr = curr->next;
	}
	printf("\n");
}
