/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessyca.costa <jessyca.costa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:47:58 by jessyca.cos       #+#    #+#             */
/*   Updated: 2025/03/20 18:50:12 by jessyca.cos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);
*/

#include <stdio.h>

char *ft_strcpy(char *s1, char *s2)
{
    int i = 0;
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i]= '\0';
    return (s1);
}

int main (int argc, char *argv[])
{
    if (argc == 2)
    {
        char s1[20];
        char *s2 = argv[1];
        printf("%s", ft_strcpy(s1, s2));
    }
    return (0);
}