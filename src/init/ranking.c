/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:26:18 by omaly             #+#    #+#             */
/*   Updated: 2025/09/16 17:26:19 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void bubble_sort(int *arr, int size)
{
    int i, j, tmp;

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

unsigned int get_rank(int *sorted, size_t size, int find)
{
	if (!sorted)
		return 0;
	unsigned int i = 0;
	while (i < size)
	{
		if (find == sorted[i])
			return i;
		i++;
	}
	return 0;
}

int *ft_arrcpy(const int*src, size_t n)
{
	if (!src)
		return NULL;
	int *cpy = malloc(n * sizeof(int));
	if (!cpy)
		return NULL;
	unsigned int i = 0;
	while (i < n)
	{
		cpy[i] = src[i];
		i++;
	}
	return (cpy);
}

unsigned int *get_ranked_arr(int *arr, size_t size)
{
	if (!arr)
		return NULL;

	int *arr_cpy = ft_arrcpy(arr,size);
	bubble_sort(arr, size);

	unsigned int *res = malloc(size * sizeof(unsigned int));
	if (!res){
		free(arr_cpy);
		return NULL;
	}
	unsigned int i = 0;
	while (i < size)
	{
		int find = arr_cpy[i];
		res[i] = get_rank(arr,size,find);
		i++;
	}
	free(arr_cpy);
	return res;
}
