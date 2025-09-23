/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:33:48 by omaly             #+#    #+#             */
/*   Updated: 2025/09/23 15:03:37 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

unsigned int	get_param_count(char **params)
{
	size_t			count;
	unsigned int	i;

	count = 0;
	i = 0;
	while (params && params[i] != NULL)
	{
		count++;
		i++;
	}
	return (count);
}

int	handle_argv(char **argv, size_t param_count, size_t start)
{
	size_t	i;
	size_t	j;
	int		i_value;
	int		j_value;

	i = start;
	while (i < param_count)
	{
		if (ps_atoi(argv[i], &i_value) != 0)
			return (1);
		j = i + 1;
		while (j < param_count)
		{
			if (ps_atoi(argv[j], &j_value) != 0)
				return (2);
			if (i_value == j_value)
				return (3);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_args(int argc, char **argv)
{
	char	**params;
	size_t	param_count;
	int		res;

	if (argc == 2)
	{
		params = ft_split(argv[1], ' ');
		if (!params)
			return (1);
		param_count = get_param_count(params);
		res = handle_argv(params, param_count, 0);
		free_split(params);
		return (res);
	}
	else if (argc > 2)
		return (handle_argv(argv, argc, 1));
	return (0);
}
