
#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *tmp;
	t_list *arr;

	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	arr = *begin_list;
	while (arr && arr->next)
	{
		if (cmp(arr->next->data, data_ref) == 0)
		{
			tmp = arr->next;
			arr->next = tmp->next;
			free(tmp);
		}
		arr = arr->next;
	}
}

/*
Assignment name : ft_list_remove_if
Expected files : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------
Write a function called ft_list_remove_if that removes from the passed
list any element the data of which is "equal" to the reference data.

It will be declared as follows :
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.
You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct s_list
{
	struct s_list *next;
	void *data;
}				t_list;
$>


*/
