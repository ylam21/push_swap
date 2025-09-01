#include "../includes/list.h"
#include "../includes/utils.h"

int is_descending(t_list **stack)
{
	if (!stack || (*stack)->next == NULL)
		return 1;
	int max;
	t_list *curr = *stack;
	while (curr->next)
	{
		max = curr->d;
		if (max < curr->next->d)
			return 0;
		curr = curr->next;
	}
	return 1;
}

int is_ascending(t_list **stack)
{
	if (!stack || (*stack)->next == NULL)
		return 1;
	int min;
	t_list *curr = *stack;
	while (curr->next)
	{
		min = curr->d;
		if (min > curr->next->d)
			return 0;
		curr = curr->next;
	}
	return 1;
}
