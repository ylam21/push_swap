#include "push_swap.h"

t_list *ft_lstnew(void *content)
{
	t_list *node = malloc(sizeof(t_list));
	if (!node)
		return NULL;
	node->content = content;
	node->next = NULL;
	return node;
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst ||	!new)
		return;
	new->next = *lst;
	*lst = new;
}

int ft_lstsize(t_list *lst)
{
	int size = 0;
	if (!lst)
		return size;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return size;
}

t_list *ft_lstlast(t_list *lst)
{
	t_list *prev;

	prev = lst;

	while (lst)
	{
		prev = lst;
		lst = lst->next;
	}
	return prev;
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;
	if (!lst || !*lst)
		return;
	last = ft_lstlast(*lst);
	if (!last)
		return;
	last->next = new;
}
