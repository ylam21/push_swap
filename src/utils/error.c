/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:20:18 by omaly             #+#    #+#             */
/*   Updated: 2025/09/28 15:39:17 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_error(int fd)
{
	write(fd, "Error\n", 6);
}

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
		printf("%d ", *(int *)curr->content);
		curr = curr->next;
	}
	printf("\n");
}
