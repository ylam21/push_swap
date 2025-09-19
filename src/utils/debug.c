/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 15:02:44 by omaly             #+#    #+#             */
/*   Updated: 2025/09/19 17:33:00 by omaly            ###   ########.fr       */
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
		printf("%d ", *(int *)curr->content);
		curr = curr->next;
	}
	printf("\n");
}

void	print_array(int *arr, size_t n)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (i < n)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

void	print_uarray(unsigned int *arr, size_t n)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (i < n)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}
