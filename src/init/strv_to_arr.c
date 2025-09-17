/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strv_to_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:56:50 by omaly             #+#    #+#             */
/*   Updated: 2025/09/17 19:11:47 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	*strv_to_arr(char **strv, int count)
{
	int				*res;
	int	i;

	if (count < 1 || !strv)
		return (NULL);
	res = malloc(sizeof(int) * count);
	if (!res)
		return (NULL);
	i = 0;
	while (i < count)
	{
		res[i] = ft_atoi(strv[count - i]);
		i++;
	}
	return (res);
}
