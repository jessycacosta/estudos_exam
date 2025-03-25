/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessyca.costa <jessyca.costa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:33:45 by jessyca.cos       #+#    #+#             */
/*   Updated: 2025/03/25 00:35:23 by jessyca.cos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$
*/

#include <stdio.h>
#include <stdlib.h>

int pgcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b; // Resto da divisão
        a = temp;  // Atualiza a para o valor de b
    }
    return a; // O último valor de a é o PGCD
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
        unsigned int a = atoi(av[1]);
        unsigned int b = atoi(av[2]);
 		printf("%u\n", pgcd(a, b));
	}
}