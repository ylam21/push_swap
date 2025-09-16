/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:26:00 by omaly             #+#    #+#             */
/*   Updated: 2025/09/16 17:26:14 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int *parse_args(int argc, char **argv)
{
	if (argc < 1 || !argv)
		return NULL;
	int *res = malloc(sizeof(int) * argc - 1);
	if (!res)
		return NULL;
	int i = 0;
	while (i < argc - 1)
	{
		res[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return res;
}
