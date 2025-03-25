/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessyca.costa <jessyca.costa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:53:47 by jessyca.cos       #+#    #+#             */
/*   Updated: 2025/03/18 21:08:32 by jessyca.cos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
*/

#include <stdio.h>

char *ft_strrev(char *str)
{
    int i = 0;
    int len = 0;
    char temp;

    while (str[len])
        len++;
    while (i < len - 1)
    {
        temp = str[i];
        str[i] = str[len - 1];
        str[len - 1] = temp;
        i++;
        len--;
    }
    return (str);
}

int main (int argc, char *argv[])
{
    if (argc == 2)
        printf("%s \n", ft_strrev(argv[1]));
    return (0);
}