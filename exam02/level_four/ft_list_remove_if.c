/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessyca.costa <jessyca.costa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:58:36 by jessyca.cos       #+#    #+#             */
/*   Updated: 2025/03/25 12:27:34 by jessyca.cos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$>
*/

#include <stdio.h>

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

void	ft_list_remove_if (t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *curr = *begin_list;
	t_list *remove;

	While(curr && curr->next)
	{
		if((cmp)(curr->next->data, data_ref) == 0)
		{
			remove = curr->next;
			curr->next = curr->next->next;
			free(remove);
		}
		curr = curr->next;
	}
	curr = *begin_list;
	if (curr && (cmp)(curr->data, data_ref) == 0)
	{
		*begin_list = curr->next;
		free(curr);
	}
}


/* #include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;


int cmp(void *data1, void *data2)
{
    return (*(int *)data1 == *(int *)data2) ? 0 : 1;  // Comparação de inteiros
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *curr = *begin_list;
    t_list *remove;

    while (curr && curr->next)
    {
        if (cmp(curr->next->data, data_ref) == 0)
        {
            remove = curr->next;
            curr->next = curr->next->next;
            free(remove);
        }
        curr = curr->next;
    }
    curr = *begin_list;
    if (curr && cmp(curr->data, data_ref) == 0)
    {
        *begin_list = curr->next;
        free(curr);
    }
}

// Função para criar um novo nó
t_list *create_node(void *data)
{
    t_list *node = malloc(sizeof(t_list));
    node->data = data;
    node->next = NULL;
    return node;
}

// Função para imprimir a lista
void print_list(t_list *list)
{
    while (list)
    {
        printf("%d -> ", *(int *)list->data);
        list = list->next;
    }
    printf("NULL\n");
}

int main()
{
    t_list *list = NULL;

    // Criando nós com valores 10, 20, 10, 30
    int data1 = 10, data2 = 20, data3 = 10, data4 = 30;
    list = create_node(&data1);
    list->next = create_node(&data2);
    list->next->next = create_node(&data3);
    list->next->next->next = create_node(&data4);

    printf("Lista antes de remover:\n");
    print_list(list);

    // Remover os nós com valor 10
    ft_list_remove_if(&list, &data1, cmp);

    printf("Lista depois de remover:\n");
    print_list(list);

    return 0;
}*/



