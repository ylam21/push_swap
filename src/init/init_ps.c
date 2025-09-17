/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:24:00 by omaly             #+#    #+#             */
/*   Updated: 2025/09/17 20:10:16 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_strv_len(char **strv)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (strv[i] != NULL)
	{
		i++;
		len++;
	}
	return (len);
}

t_list	*build_stack(int argc, char **argv)
{
	unsigned int	count;
	int				*raw;
	unsigned int	*ranked;
	char			**strv;

	strv = NULL;
	count = 0;
	if (argc == 2)
	{
		strv = ft_split(argv[1], ' ');
		count = get_strv_len(strv);
	}
	else if (argc > 2)
	{
		strv = argv;
		count = argc - 1;
	}

	raw = strv_to_arr(strv, count);
	ranked = get_ranked_arr(raw, count);
	return (arr_to_list(ranked, count));
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
