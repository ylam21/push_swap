/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:33:42 by omaly             #+#    #+#             */
/*   Updated: 2025/09/02 13:08:05 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*parse(int argc, char **argv)
{
	int		i;
	int		value;
	t_list	*head;
	t_list	*new;

	i = 0;
	value = ft_atoi(argv[argc - 1 - i]);
	i++;
	head = ft_lstnew(value);
	while (i < argc - 1)
	{
		value = ft_atoi(argv[argc - 1 - i]);
		new = ft_lstnew(value);
		ft_lstadd_back(&head, new);
		i++;
	}
	return (head);
}
