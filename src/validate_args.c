/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:33:48 by omaly             #+#    #+#             */
/*   Updated: 2025/08/20 14:30:38 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int validate_args(int argc, char **argv)
{
	if (argc < 2)
	{
		return 1;
	}
	int i = 1;
	while (i < argc)
	{
		if (is_zero(argv[i]) == 0)
		{
			if (ft_atoi(argv[i]) == 0)
			{
				return 2;
			}
		}
		int j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				return 3;
			}
			j++;
		}
		i++;
	}
	return 0;
}
