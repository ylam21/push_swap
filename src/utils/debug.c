/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:41:53 by omaly             #+#    #+#             */
/*   Updated: 2025/10/07 18:54:26 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_lst(t_list *lst)
{
	t_list *curr;

	if (!lst)
	{
		printf("NULL\n");
		return ;
	}
	curr = lst;
	while (curr)
	{
		printf("%d ", *(int *)curr->content);
		curr = curr->next;
	}
	printf("\n");
}
