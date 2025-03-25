/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessyca.costa <jessyca.costa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:28:31 by jessyca.cos       #+#    #+#             */
/*   Updated: 2025/03/25 12:47:42 by jessyca.cos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

#include <stdio.h>
#include <stdlib.h>

int len_n(int n)
{
	int len = 0;
	
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	long n = nbr;
	int len = len_n(nbr);
	char *dst = malloc(sizeof(char) * (len + 1));

	if (!dst)
		return (NULL);
	dst[len] = '\0';
	if (n == 0)
		dst[0] = '0';
	if (n < 0)
	{
		dst[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		len--;
		dst[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (dst);
}

int main()
{
    int numbers[] = {1234, -5678, 0, 42, -1};
    int i;

    // Testando com diferentes números
    for (i = 0; i < 5; i++)
    {
        char *result = ft_itoa(numbers[i]);

        if (result)  // Verifica se a alocação foi bem-sucedida
        {
            printf("Resultado para %d: %s\n", numbers[i], result);
            free(result);  // Não esqueça de liberar a memória alocada
        }
        else
        {
            printf("Erro na alocação de memória.\n");
        }
    }

    return 0;
}