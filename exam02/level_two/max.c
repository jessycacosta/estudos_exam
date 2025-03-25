/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessyca.costa <jessyca.costa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:42:08 by jessyca.cos       #+#    #+#             */
/*   Updated: 2025/03/18 22:52:12 by jessyca.cos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/

#include <stdlib.h>
#include <stdio.h>

int	max(int* tab, unsigned int len)
{
    if (len==0)
        return 0;
    unsigned int max = tab[0];
    unsigned int i = 1;
    while(i < len)
    {
        if(tab[i] > max)
            max = tab[i];
        i++;
    }
    return max;
}

int main (void)
{
    int tab[6]={1,6,22,1,10,11};
    printf("%d", max(tab,6));
    return (0);
}
