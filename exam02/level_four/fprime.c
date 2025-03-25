/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessyca.costa <jessyca.costa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:41:05 by jessyca.cos       #+#    #+#             */
/*   Updated: 2025/03/25 11:55:55 by jessyca.cos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there's one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
*/

#include <stdlib.h>
#include <stdio.h>

int main (int ac, char **av)
{
	if (ac == 2)
	{
		int i = 2;
		int num = atoi(av[1]);
		if (num == 1)
		{	
			printf("%d\n", 1);
			return (0);
		}
		while (num >= i)
		{
			if(num % i == 0)
			{
				printf("%d", i);				
				if(num == i)
					break;
				printf("*");
				num = num / i;
				i = 1;
			}
			i++;
		}
	}
	printf("\n");
    return (0);
}