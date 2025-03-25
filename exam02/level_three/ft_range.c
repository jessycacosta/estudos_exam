/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessyca.costa <jessyca.costa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:46:36 by jessyca.cos       #+#    #+#             */
/*   Updated: 2025/03/24 23:03:10 by jessyca.cos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	*array_int;
	int	size;
	int	i;

	if (start >= end)
		return (0);
	size = end - start + 1;
	array_int = (int *)malloc(size * sizeof(int));
    if (!array_int)
        return (NULL);
	i = 0;
	while (start <= end)
	{
		array_int[i] = start;
		i++;
		start++;
	}
	return (array_int);
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
	    array = ft_range(start, end);
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