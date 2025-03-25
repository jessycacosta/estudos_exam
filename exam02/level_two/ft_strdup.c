/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessyca.costa <jessyca.costa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:48:32 by jessyca.cos       #+#    #+#             */
/*   Updated: 2025/03/18 20:03:03 by jessyca.cos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);
*/

#include <stdlib.h>
#include <stdio.h>

char *ft_strdup(char *src)
{
    char *dest;
    int len = 0;
    int i = 0;
    while (src[len])
        len++;
    dest = (char *)malloc((len + 1) * (sizeof (char)));
    if (!dest)
        return (NULL);
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

int main (int argc, char *argv[])
{
    char *duplicated_string;

    if (argc == 2)
    {
        duplicated_string = ft_strdup(argv[1]);
        if (duplicated_string)
        {
            printf("%s\n", duplicated_string);
            free(duplicated_string);
        }
        else
        {
            printf("Memory allocation failed.\n");
        }
    }
    return (0);
}