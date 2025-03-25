/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessyca.costa <jessyca.costa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:53:13 by jessyca.cos       #+#    #+#             */
/*   Updated: 2025/03/24 19:02:35 by jessyca.cos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/

#include <stdio.h>

int isspace(int c)
{
     if (c <= 32)
         return (1);
     return (0);
}

int isvalid(int ch, int baselen)
{
    char *lcbase = "0123456789abcdef";
    char *ucbase = "0123456789ABCDEF";
    int i = 0;
    
    while (i < baselen)
    {
        if (ch == lcbase[i] || ch == ucbase[i])
            return (1);
        i++;
    }
    return (0);
}

int ft_atoi_base(const char *str, int str_base)
{
    int res = 0;
    int sign = 1;
    int i = 0;
    
    while (isspace(str[i]))
        i++;
    if (str[i] == '+' && str[i + 1] != '-')
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i] && isvalid(str[i], str_base))
    {
        res *= str_base;
        if (str[i] >= '0' && str[i] <= '9')
            res += str[i] - '0';
        else if (str[i] >= 'a' && str[i] <= 'f')
            res += str[i] - 'a' + 10;
        else if (str[i] >= 'A' && str[i] <= 'F')
            res += str[i] - 'A' + 10;
        i++;
    }
    return (res * sign);
}

int main()
{
    printf("%d\n", ft_atoi_base("101", 2));     // Base 2 → 5
    printf("%d\n", ft_atoi_base("1F", 16));     // Base 16 → 31
    printf("%d\n", ft_atoi_base("-42", 10));    // Base 10 → -42
    printf("%d\n", ft_atoi_base("123", 8));     // Base 8 → 83
    return 0;
}