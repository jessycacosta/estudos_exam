/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessyca.costa <jessyca.costa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:03:33 by jessyca.cos       #+#    #+#             */
/*   Updated: 2025/03/24 19:45:37 by jessyca.cos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/

#include "ft_list.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
    int i = 0;
	t_list *curr = begin_list;
	
	while(curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

t_list	*ft_lstnew(void *data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

int main (void)
{
    t_list *list_size = NULL;
	
	int val3 = 10;
	t_list *new_list3 = ft_lstnew(&val3);
	ft_lstadd_front(&list_size, new_list3);
	
	int val4 = 20;
	t_list *new_list4 = ft_lstnew(&val4);
	ft_lstadd_front(&list_size, new_list4);
	
	int val5 = 30;
	t_list *new_list5 = ft_lstnew(&val5);
	ft_lstadd_front(&list_size, new_list5);

    int val6 = 10;
	t_list *new_list6 = ft_lstnew(&val6);
	ft_lstadd_front(&list_size, new_list6);
	
	int val7 = 20;
	t_list *new_list7 = ft_lstnew(&val7);
	ft_lstadd_front(&list_size, new_list7);
	
	int val8 = 30;
	t_list *new_list8 = ft_lstnew(&val8);
	ft_lstadd_front(&list_size, new_list8);
	
	printf("%d\n", ft_list_size(list_size));
}