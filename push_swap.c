#include "includes/validate_args.h"
#include "includes/parse.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int ret = validate_args(argc, argv);
	if (ret != 0)
	{
		write(2,"Error\n",6);
		return ret;
	}
	t_list *stack_a = parse(argc, argv);
	t_list *prev = stack_a;
	while (stack_a)
	{
		int d = stack_a->d;
		printf("%i ",d);
		prev = stack_a;
		stack_a = stack_a->next;
		free(prev);
	}
	printf("\nSuccess\n");
    return ret;
}
