/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:33:46 by omaly             #+#    #+#             */
/*   Updated: 2025/08/28 21:42:17 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/validate_args.h"
#include "../includes/utils.h"
#include "../includes/parse.h"
#include "../includes/operations.h"
#include "../includes/list.h"

// TODO: fn for calculating path to top for number n
// TODO: fn when to use RRR or SS
int is_sorted(t_list *stack);

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
