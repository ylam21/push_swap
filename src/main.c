#include "push_swap.h"

int ft_atoi(const char *s);
int is_zero(const char *s);

int main(int argc, char **argv)
{
    if (argc < 2)
	{
		write(2,"Error\n",6);
		return 1;
	}
	int i = 1;
	while (i < argc)
	{
		char *param = argv[i];
		if (is_zero(param) == 0)
		{
			if (ft_atoi(param) == 0)
			{
				write(2,"Error\n",6);
				return 2;
			}
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		printf("%s ",argv[i]);
		i++;
	}
	printf("\nSuccess\n");
    return 0;
}
