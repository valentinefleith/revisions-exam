#include "sort_list.h"
#include <stdlib.h>
#include <stdio.h>

t_list *ft_lstnew(int content)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return NULL;
	new->data = content;
	new->next = NULL;
	return new;
}

void ft_lstadd_back(t_list **lst, t_list *node)
{
	t_list *last;

	last = *lst;

	if (!*lst)
	{
		*lst = node;
		return;
	}
	while (last->next)
		last = last->next;
	last->next = node;
}

void ft_printlst(t_list *lst)
{
	while (lst)
	{
		if (lst->next)
			printf("%i->", lst->data);
		else
			printf("%i\n", lst->data);
		lst = lst->next;
	}
}

void ft_swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
	if (!lst)
		return NULL;
	t_list *start = lst;
	int swap_count = 1;
	while (swap_count != 0)
	{
		swap_count = 0;
		lst = start;
		while (lst->next)
		{
			if (!(*cmp)(lst->data, lst->next->data))
			{
				ft_swap(&(lst->data), &(lst->next->data));
				swap_count++;
			}
			lst = lst->next;
		}
	}
	return start;
}

int is_right_order(int a, int b)
{
	return (a <= b);
}

int main(void)
{
	t_list *lst = NULL;
	const int nbs[] = {5, 3, 1, 9, 2, 2};
	//const int nbs[] = {5};
	//const int nbs[] = {};
	size_t size = sizeof(nbs) / sizeof(*nbs);
	for (size_t i = 0; i < size; i++)
	{
		ft_lstadd_back(&lst, ft_lstnew(nbs[i]));
	}

	ft_printlst(lst);
	sort_list(lst, &is_right_order);
	ft_printlst(lst);
}
