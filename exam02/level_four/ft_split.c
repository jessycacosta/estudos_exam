/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessyca.costa <jessyca.costa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:48:05 by jessyca.cos       #+#    #+#             */
/*   Updated: 2025/03/25 13:03:50 by jessyca.cos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/

#include <stdio.h>
#include<stdlib.h>

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int i = 0;

	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char    **ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int wd = 0;
	char **dst;

	while (str[i])
	{
		while (str[i] == 32 || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i])
			wd++;
		while (str[i] != 32 && str[i] != '\t'&& str[i] != '\n' && str[i] != '\0')
			i++;
	}
	dst = (char **)malloc(sizeof(char *) * (wd + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (str[i])
	{
		while (str[i] == 32 || str[i] == '\t' || str[i] == '\n')
			i++;
		j = i;
		while (str[i] != 32 && str[i] != '\t'&& str[i] != '\n' && str[i] != '\0')
			i++;
		if (i > j)
		{
			dst[k] = (char *)malloc(sizeof(char *) * (i-j + 1));
			if (!dst)
				return (NULL);
			ft_strncpy(dst[k], &str[j], i - j);
			k++;
		}
	}
	dst[k] = NULL;
	return (dst);
}

int main(void)
{
    char *str = "Hello   World!  This is a test";
    char **result;
    int i = 0;

    // Chama a função ft_split para dividir a string
    result = ft_split(str);

    // Imprime o resultado
    if (result)
    {
        while (result[i] != NULL)
        {
            printf("Word %d: %s\n", i + 1, result[i]);
            free(result[i]);  // Libera a memória alocada para cada palavra
            i++;
        }
        free(result);  // Libera a memória do array de palavras
    }

    return 0;
}