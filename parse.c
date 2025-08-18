#include <stdlib.h>
#include "includes/parse.h"
#include "includes/validate_args.h"

t_list *ft_lstnew(int d)
{
	t_list *lst = malloc(sizeof(t_list));
	if (!lst)
		return NULL;
	lst->d = d;
	lst->next = NULL;
	return lst;
}

t_list *ft_lstlast(t_list *lst)
{
	if (!lst)
		return NULL;
	while (lst->next)
		lst = lst->next;
	return lst;
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;
	if (!lst || !*lst)
		return;
	if (!*lst)
	{
		*lst = new;
		return;
	}

	last = ft_lstlast(*lst);
	last->next = new;
}

t_list *parse(int argc, char **argv)
{
	int i = 1;
	int value = ft_atoi(argv[i]);
	i++;
	t_list *head = ft_lstnew(value);
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		t_list *new = ft_lstnew(value);
		ft_lstadd_back(&head,new);
		i++;
	}
	return head;
}
