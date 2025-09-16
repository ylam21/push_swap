#include "../../includes/push_swap.h"

void print_arr(const int *arr, size_t size)
{
	if (!arr)
		return;
	unsigned int i = 0;
	while (i < size)
	{
		printf("%d ",arr[i]);
		i++;
	}
	printf("\n");
}

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

unsigned int *normalize(int *arr, size_t size)
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
