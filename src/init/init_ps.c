/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:24:00 by omaly             #+#    #+#             */
/*   Updated: 2025/09/19 17:32:43 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*build_stack(int argc, char **argv)
{
	int				allocated;
	char			**tokens;
	t_list			*stack;
	unsigned int	offset;

	offset = 0;
	stack = NULL;
	tokens = NULL;
	allocated = 0;
	if (argc == 2)
	{
		tokens = ft_split(argv[1], ' ');
		allocated = 1;
	}
	else
	{
		tokens = argv;
		offset = 1;
	}
	if (!tokens)
		return (NULL);
	stack = tokens_to_lst(tokens, offset);
	if (allocated)
		free_split(tokens);
	return (stack);
}

int	init_ps(t_ps *ps, int argc, char **argv)
{
	ps->stack_a = build_stack(argc, argv);
	if (!ps->stack_a)
		return (1);
	ps->stack_b = NULL;
	ps->size_a = ft_lstsize(ps->stack_a);
	ps->max_a = get_max(ps->stack_a);
	return (0);
}
