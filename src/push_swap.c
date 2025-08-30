/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:33:46 by omaly             #+#    #+#             */
/*   Updated: 2025/08/30 23:23:32 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/validate_args.h"
#include "../includes/utils.h"
#include "../includes/parse.h"
#include "../includes/operations.h"
#include "../includes/list.h"

// TODO: fn when to use RRR or SS
int is_sorted(t_list *stack);

int get_index(t_list **stack, int number)
{
	if (!stack || !(*stack))
		return -1;
	int index = 0;
	t_list *curr = *stack;
	while (curr)
	{
		if (curr->d == number)
			return index;
		index++;
		curr = curr->next;
	}
	return -2;
}

int distance_to_top(int max_index, int index)
{
	if (index < 0)
		return -1;
	if (index == max_index)
		return 0;
	int middle = max_index / 2;
	if (index >= middle)
		return middle - index;
	else
		return index + 1;
}

void print_stack(t_list *stack)
{
	if (!stack)
		return;
	t_list *curr = stack;
	while (curr)
	{
		printf("%d ",curr->d);
		curr = curr->next;
	}
	printf("\n");
}

void push_swap(t_list **stack_a)
{
	if (is_sorted(*stack_a) != 0)
	{
		// swap(stack_a);
		// rotate(stack_a);
		// reverse_rotate(stack_a);
	}
	return;
}

int main(int argc, char **argv)
{
	int ret = validate_args(argc, argv);
	if (ret != 0)
	{
		write(2,"Error\n",6);
		return ret;
	}
	t_list *stack_a = parse(argc, argv);
	print_stack(stack_a);
	push_swap(&stack_a);
	print_stack(stack_a);
	if (is_sorted(stack_a) == 0)
		printf("Stack A is sorted.\n");
	t_list *prev = stack_a;
	while (stack_a)
	{
		prev = stack_a;
		stack_a = stack_a->next;
		free(prev);
	}
    return ret;
}
