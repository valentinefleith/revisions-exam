#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *))
{
	if (!begin_list)
		return;
	while (*begin_list)
	{
		if (!(*cmp)((*begin_list)->data, data_ref))
		{
			t_list *next;
			next = (*begin_list)->next;
			free((*begin_list)->data);
			free(*begin_list);
			*begin_list = next;
		}
		*begin_list = (*begin_list)->next;
	}
}
