/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessyca.costa <jessyca.costa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:42:52 by jessyca.cos       #+#    #+#             */
/*   Updated: 2025/03/18 18:51:22 by jessyca.cos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);
*/

#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while ((s1[i] || s2[i]) && (s1[i] == s2[i]))
        i++;
    return (s1[i] - s2[i]);
}

int main (int argc, char *argv[])
{
    if (argc == 3)
        printf("%d \n", ft_strcmp(argv[1], argv[2]));
    return (0);
}