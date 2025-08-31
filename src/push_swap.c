/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:33:46 by omaly             #+#    #+#             */
/*   Updated: 2025/08/31 23:36:58 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/validate_args.h"
#include "../includes/utils.h"
#include "../includes/parse.h"
#include "../includes/operations.h"
#include "../includes/list.h"

int is_sorted(t_list **stack);

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
	return -1;
}

int distance_to_top(int size, int index)
{
	if (index < 0 || size < 0)
		return -1;
	if (index == size - 1)
		return 0;
	int middle = (size - 1) / 2;
	if (index >= middle)
		return size - index;
	else
		return index + 1;
}

void print_stack(t_list **stack)
{
	if (!*stack || !stack)
	{
		printf("NULL\n");
		return;
	}
	t_list *curr = *stack;
	while (curr)
	{
		printf("%d ",curr->d);
		curr = curr->next;
	}
	printf("\n");
}

int get_minimum(t_list **stack)
{
	t_list *curr = *stack;
	int min = curr->d;
	while (curr)
	{
		if (curr->d < min)
			min = curr->d;
		curr = curr->next;
	}
	return min;
}

int get_maximum(t_list **stack)
{
	t_list *curr = *stack;
	int max = curr->d;
	while (curr)
	{
		if (curr->d > max)
			max = curr->d;
		curr = curr->next;
	}
	return max;
}

int get_closer_index(int index_a, int index_b, int size)
{
	if (index_a < 0 || index_b < 0 || size < 0)
		return -1;
	int dist_a = distance_to_top(size, index_a);
	int dist_b = distance_to_top(size, index_b);
	if (dist_a <= dist_b)
		return index_a;
	else
		return index_b;
}

void get_bound_to_top(t_list **stack)
{
	if (!stack || !(*stack))
		return;
	int size = ft_lstsize(*stack);
	int min = get_minimum(stack);
	int max = get_maximum(stack);
	int min_index = get_index(stack, min);
	int max_index = get_index(stack, max);
	int closer = get_closer_index(min_index,max_index,size);
	int counter = 0;
	while (counter < distance_to_top(size, closer))
	{
		if (closer > (size - 1) / 2)
			rotate(stack);
		else
			reverse_rotate(stack);
		counter++;

	}
}

void rearrange_recent_push(t_list **stack)
{
	if (!stack || !(*stack))
		return;

}

void rearrange_stack_b_for_push_to_a(t_list **stack)
{
	if (!stack || !(*stack))
		return;
	int size = ft_lstsize(*stack);
	int max = get_maximum(stack);
	int max_index = get_index(stack,max);
	int dist = distance_to_top(size,max_index);
	int counter = 0;
	while (counter < dist)
	{
		if (max_index > (size - 1) / 2)
			rotate(stack);
		else
			reverse_rotate(stack);
		counter++;
	}

}

void empty_stack_a(t_list **stack_a, t_list **stack_b)
{
	int bound_max = get_maximum(stack_a);
	while (*stack_a != NULL)
	{
		printf("max: %d\n",bound_max);
		get_bound_to_top(stack_a);
		push(stack_a,stack_b);
		t_list *node_last = ft_lstlast(*stack_b);
		int lstlast = 0;
		if (node_last != NULL)
		lstlast = node_last->d;
		if (lstlast == bound_max - 1 || lstlast == bound_max)
		{
			if (lstlast == bound_max - 1)
			bound_max = bound_max - 1;
			rotate(stack_b);
		}
		printf("stack B:\n");
		print_stack(stack_b);
	}
	rearrange_stack_b_for_push_to_a(stack_b);
}

void push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	int counter = 0;
	int size = ft_lstsize(*stack_b);
	while (counter < size)
	{
		push(stack_b,stack_a);
		counter++;
	}
}
void push_swap(t_list **stack_a, t_list **stack_b)
{
	empty_stack_a(stack_a,stack_b);
	push_back_to_a(stack_a,stack_b);
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
	t_list *stack_b = NULL;
	if (is_sorted(&stack_a) == 0)
		push_swap(&stack_a,&stack_b);
	if (is_sorted(&stack_a) == 1)
		printf("Stack A is sorted.\n");
	print_stack(&stack_a);
	t_list *prev = stack_a;
	while (stack_a)
	{
		prev = stack_a;
		stack_a = stack_a->next;
		free(prev);
	}
    return ret;
}
