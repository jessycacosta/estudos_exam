/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessyca.costa <jessyca.costa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:19:48 by jessyca.cos       #+#    #+#             */
/*   Updated: 2025/03/18 12:37:10 by jessyca.cos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);
*/

#include <stdio.h>
#include <stdlib.h>

void ft_swap(int *a, int *b)
{
    int swap;
    swap = *a;
    *a = *b;
    *b = swap;
}

int main (int argc, char *argv[])
{
    if (argc == 3)
    {
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);
        ft_swap(&a, &b);
        printf("%d %d \n", a, b);
    }
    return (0);
}