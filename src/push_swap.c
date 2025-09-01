/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:33:46 by omaly             #+#    #+#             */
/*   Updated: 2025/09/01 13:12:09 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/validate_args.h"
#include "../includes/utils.h"
#include "../includes/parse.h"
#include "../includes/operations.h"
#include "../includes/list.h"

int is_descending(t_list **stack);
int is_ascending(t_list **stack);

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

void get_bound_to_top(t_list **stack, char c)
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
		{
			rotate(stack);
			printf("rotate %c\n",c);
		}
		else
		{
			reverse_rotate(stack);
			printf("reverse rotate %c\n",c);
		}
		counter++;
	}
}

void get_max_to_top(t_list **stack, char c)
{
	if (!stack || !(*stack))
		return;
	int size = ft_lstsize(*stack);
	int max = get_maximum(stack);
	int max_index = get_index(stack,max);
	int dist = (size - 1) - max_index;
	int counter = 0;
	while (counter < dist)
	{
		rotate(stack);
		printf("rotate %c\n",c);
		counter++;
	}
}

void empty_stack_a(t_list **stack_a, t_list **stack_b)
{
	int max_num = get_maximum(stack_a);
	int prev = max_num;
	while (*stack_a != NULL)
	{
		int	min_num = get_minimum(stack_a);
		if (ft_lstsize(*stack_b) != 0)
		 	prev = ft_lstlast(*stack_b)->d;
		get_bound_to_top(stack_a,'a');
		push(stack_a,stack_b);
		printf("pb\n");
		int curr = ft_lstlast(*stack_b)->d;
		if (curr != prev + 1 && curr != min_num)
		{
			rotate(stack_b);
			printf("rotate b\n");
		}
		printf("stack B:\n");
		print_stack(stack_b);
	}
}

void push_swap(t_list **stack_a)
{
	t_list *stack_b = NULL;
	empty_stack_a(stack_a, &stack_b);
	if (is_ascending(&stack_b) == 0)
		get_max_to_top(&stack_b,'b');
	int i = 0;
	int size = ft_lstsize(stack_b);
	while (i < size)
	{
		push(&stack_b, stack_a);
		printf("pa\n");
		i++;
	}
}
int main(int argc, char **argv)
{
	// Validate input
	if (validate_args(argc, argv) != 0)
		return (write(2,"Error\n",6), 1);

	// Parse arguments to linked list
	t_list *stack_a;
	stack_a = parse(argc, argv);

	// Push swap algorithm
	if (is_descending(&stack_a) == 0)
		push_swap(&stack_a);

	print_stack(&stack_a);
	// Free allocated memory
	t_list *prev = stack_a;
	while (stack_a)
	{
		prev = stack_a;
		stack_a = stack_a->next;
		free(prev);
	}
    return 0;
}
