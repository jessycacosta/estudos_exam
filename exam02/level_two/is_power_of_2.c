/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessyca.costa <jessyca.costa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:26:08 by jessyca.cos       #+#    #+#             */
/*   Updated: 2025/03/24 12:40:55 by jessyca.cos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);
*/

#include <stdio.h>
#include <stdlib.h>

int is_power_of_2(unsigned int n)
{
    /* int test = 1;
    while (test <= n)
    {
        if (test == n)
            return (1);
        test = test * 2;
    }
    return (0);*/
    return (n > 0 && (n & (n - 1)) == 0);       
}

int main (int argc, char *argv[])
{
    int n = atoi(argv[1]);
    if (argc == 2)
        printf("%d \n", is_power_of_2((unsigned int)n));
    return (0);
}