/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaly <omaly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:33:46 by omaly             #+#    #+#             */
/*   Updated: 2025/08/21 23:08:24 by omaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/validate_args.h"
#include "../includes/utils.h"
#include "../includes/parse.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// TODO: write function that check if list is sorted
// TODO: fn for calculating path to top for number n
// TODO: fn when to use RRR or SS
// TODO:

// void push_swap(t_list *stack_a)
// {
// 	// case for :1
// 	// case for :2
// 	// case for :3
// 	// case for :5
// 	// case for :5<
// }


int main(int argc, char **argv)
{
	int ret = validate_args(argc, argv);
	if (ret != 0)
	{
		write(2,"Error\n",6);
		return ret;
	}
	t_list *stack_a = parse(argc, argv);
	t_list **head = &stack_a;
	// main logic
	// try swap
	swap(&stack_a);
	t_list *prev = stack_a;
	stack_a = *head;
	while (stack_a)
	{
		int d = stack_a->d;
		printf("%i ",d);
		prev = stack_a;
		stack_a = stack_a->next;
		free(prev);
	}
    return ret;
}
