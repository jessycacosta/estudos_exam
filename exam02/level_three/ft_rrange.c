/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessyca.costa <jessyca.costa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:18:49 by jessyca.cos       #+#    #+#             */
/*   Updated: 2025/03/24 23:05:20 by jessyca.cos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/

#include <stdlib.h>
#include <stdio.h>

/*
int val_abs(int a,int b)
{
    if(a >= b)
        return(a - b);
    else
        return(b - a);
}
*/

int *ft_rrange(int start, int end)
{
    int i = 0;
    int size = (end - start) < 0 ? ((end - start) * -1) + 1 : (end - start) + 1;
    int *range = (int *)malloc(size * sizeof(int));
    while (i < size)
    {
        if (end < start)
            range[i] = end++;
        else
            range[i] = end--;
        i++;
    }
    return (range);
}

int	main(int argc, char **argv)
{
    if (argc == 3)
    {
        int i = 0;
        int *array;
        int start = atoi(argv[1]);
        int end = atoi(argv[2]);
        int size = (end - start) < 0 ? ((end - start) * -1) + 1 : (end - start) + 1;
        int cols = 10;
	    array = ft_rrange(start, end);
        if (!array)
            return (1);
        while (i < size)
	    {
		    printf("%4d ", array[i]);
            if ((i + 1) % cols == 0)
                printf("\n");
		    i++;
	    }
        printf("\n");
	free(array);
    }
	return (0);
}