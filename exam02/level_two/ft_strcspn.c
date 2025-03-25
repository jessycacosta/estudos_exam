/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessyca.costa <jessyca.costa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:52:01 by jessyca.cos       #+#    #+#             */
/*   Updated: 2025/03/18 19:23:33 by jessyca.cos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);
*/

#include <stdio.h>

/*
size_t ft_strlen(const char *str)
{
    size_t i = 0;
    while (*str != '\0')
    {
        i++;
        str++;
    }
    return (i);
}

size_t ft_ispresent(char c, const char *str)
{
    size_t i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

size_t ft_strcspn(const char *s, const char *reject)
{
    int i = 0;
    while (s[i])
    {
        if (ft_ispresent(s[i], reject) == 1)
            return (i);
        i++;
    }
    return (ft_strlen(s));
}

int main (int argc, const char *argv[])
{
    if (argc == 3)
        printf("%zu \n", ft_strcspn(argv[1], argv[2]));
    return (0);
}
*/

size_t ft_strcspn(const char *s, const char *reject)
{
    const char *s_start = s;
    const char *r;

    while (*s)
    {
        r = reject;
        while (*r)
        {
            if (*s == *r)
                return (s - s_start);
            r++;
        }
        s++;
    }
    return (s - s_start);
}

int main(int argc, const char *argv[])
{
    if (argc == 3)
        printf("%zu\n", ft_strcspn(argv[1], argv[2]));
    return (0);
}