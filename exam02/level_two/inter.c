/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessyca.costa <jessyca.costa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:09:56 by jessyca.cos       #+#    #+#             */
/*   Updated: 2025/03/18 21:39:32 by jessyca.cos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_is_in_string(char c, char *str)
{
    while (*str)
    {
        if (*str == c)
            return (1);
        str++;
    }
    return (0);
}

int ft_is_first_occurrence(char c, char *str, int position)
{
    int i = 0;
    while (i < position)
    {
        if (str[i] == c)
            return (0);
        i++;
    }
    return (1);
}

int main(int argc, char *argv[])
{
    int i;

    if (argc == 3)
    {
        i = 0;
        while (argv[1][i])
        {
            if (ft_is_in_string(argv[1][i], argv[2]) && ft_is_first_occurrence(argv[1][i], argv[1], i))
                ft_putchar(argv[1][i]);
            i++;
        }
    }
    ft_putchar('\n');
    return (0);
}
