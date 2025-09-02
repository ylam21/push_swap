/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:14:59 by omaly             #+#    #+#             */
/*   Updated: 2025/09/02 11:17:30 by omaly            ###   ########.fr       */
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
		printf("%d ", curr->d);
		curr = curr->next;
	}
	printf("\n");
}
