/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:30:01 by omaly             #+#    #+#             */
/*   Updated: 2025/10/01 13:16:17 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_max(t_list *lst)
{
	t_list	*curr;
	int		max;

	curr = lst;
	max = *(int *)curr->content;
	while (curr)
	{
		if (*(int *)curr->content > max)
			max = *(int *)curr->content;
		curr = curr->next;
	}
	return (max);
}

int	is_descending(t_list *lst)
{
	int		max;
	t_list	*curr;

	if (!lst)
		return (0);
	curr = lst;
	while (curr->next)
	{
		max = *(int *)curr->content;
		if (max < *(int *)curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	get_target_pos(t_list *lst, unsigned int target)
{
	int		pos;
	t_list	*curr;

	if (!lst)
		return (-1);
	pos = 0;
	curr = lst;
	while (curr)
	{
		if (target == *(unsigned int *)curr->content)
			return (pos);
		pos++;
		curr = curr->next;
	}
	return (pos);
}

unsigned int	get_num_bits(unsigned int num)
{
	unsigned int	num_bits;

	num_bits = 0;
	while (num >> num_bits != 0)
		++num_bits;
	return (num_bits);
}
