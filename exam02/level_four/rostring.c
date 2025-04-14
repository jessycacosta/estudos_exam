/* Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>*/

#include <unistd.h>

void rostring(char *s)
{
    int i = 0;
    int start = 0;
    int end = 0;
    int first = 1;

    // Pular espaços iniciais
    while (s[i] == ' ' || s[i] == '\t')
        i++;

    // Guardar início e fim da primeira palavra
    start = i;
    while (s[i] && s[i] != ' ' && s[i] != '\t')
        i++;
    end = i;

    // Imprimir o resto das palavras
    while (s[i])
    {
        // Pular espaços
        while (s[i] == ' ' || s[i] == '\t')
            i++;
        if (s[i] == '\0')
            break;

        // Se não for a primeira palavra, imprime espaço antes
        if (!first)
            write(1, " ", 1);
        first = 0;

        // Imprimir a palavra
        while (s[i] && s[i] != ' ' && s[i] != '\t')
        {
            write(1, &s[i], 1);
            i++;
        }
    }

    // Se houver mais de uma palavra, imprimir espaço antes da primeira
    if (!first)
        write(1, " ", 1);

    // Imprimir a primeira palavra
    while (start < end)
    {
        write(1, &s[start], 1);
        start++;
    }
}

int main(int ac, char **av)
{
    if (ac > 1 && *av[1])
        rostring(av[1]);
    write(1, "\n", 1);
    return 0;
}