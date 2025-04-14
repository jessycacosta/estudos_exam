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