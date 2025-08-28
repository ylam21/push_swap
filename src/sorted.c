#include "../includes/list.h"
#include "../includes/utils.h"

int is_sorted(t_list *stack)
{
	if (!stack || stack->next == NULL)
		return 0;
	int max;
	t_list *curr = stack;
	while (curr->next)
	{
		max = curr->d;
		if (max < curr->next->d)
			return 1;
		curr = curr->next;
	}
	return 0;
}
