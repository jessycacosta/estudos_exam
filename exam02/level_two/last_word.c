/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecosta <jecosta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:39:59 by jessyca.cos       #+#    #+#             */
/*   Updated: 2025/04/14 16:47:10 by jecosta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/

#include <unistd.h>

void ft_laststr(char *str, int start, int end)
{
    while (start < end)
        write(1, &str[start++], 1);
}

int main (int ac, char **av)
{
    if (ac == 2)
    {
        char *str = av[1];
        int i = 0;
        while (str[i])
            i++;
        while (i > 0 && str[i - 1] == ' ')
            i--;
        int end = i;
        while (i > 0 && str[i - 1] != ' ')
            i--;
        ft_laststr(str, i, end);
    }
    write (1, "\n", 1);
    return (0);
}