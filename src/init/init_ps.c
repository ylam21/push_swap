/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:24:00 by omaly             #+#    #+#             */
/*   Updated: 2025/10/07 18:16:51 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*build_lst(int argc, char **argv)
{
	int				allocated;
	char			**tokens;
	t_list			*lst;
	unsigned int	offset;

	offset = 0;
	lst = NULL;
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
	lst = tokens_to_lst(tokens, offset);
	if (allocated)
		free_split(tokens);
	return (lst);
}

int	init_ps(t_ps *ps, int argc, char **argv)
{
	ps->lst_a = build_lst(argc, argv);
	if (!ps->lst_a)
		return (1);
	ps->lst_b = NULL;
	return (0);
}
