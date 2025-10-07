/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:26:18 by omaly             #+#    #+#             */
/*   Updated: 2025/10/07 18:34:15 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

unsigned int	get_rank(int *sorted, int size, int find)
{
	int	i;

	if (!sorted)
		return (0);
	i = 0;
	while (i < size)
	{
		if (find == sorted[i])
			return (i);
		i++;
	}
	return (0);
}

int	*ft_arrcpy(const int *src, int n)
{
	int	*cpy;
	int	i;

	if (!src)
		return (NULL);
	cpy = malloc(n * sizeof(int));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < n)
	{
		cpy[i] = src[i];
		i++;
	}
	return (cpy);
}

unsigned int	*get_ranked_arr(int *arr, int size)
{
	int				*arr_cpy;
	unsigned int	*res;
	int				i;
	int				find;

	if (!arr)
		return (NULL);
	arr_cpy = ft_arrcpy(arr, size);
	bubble_sort(arr, size);
	res = malloc(size * sizeof(unsigned int));
	if (!res)
	{
		free(arr_cpy);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		find = arr_cpy[i];
		res[i] = get_rank(arr, size, find);
		i++;
	}
	free(arr_cpy);
	return (res);
}
