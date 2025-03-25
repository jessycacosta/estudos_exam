/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessyca.costa <jessyca.costa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:22:48 by jessyca.cos       #+#    #+#             */
/*   Updated: 2025/03/25 11:39:21 by jessyca.cos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : flood_fill
Expected files   : *.c, *.h
Allowed functions: -
--------------------------------------------------------------------------------
Write a function that takes a char ** as a 2-dimensional array of char, a 
t_point as the dimensions of this array and a t_point as the starting point.
Starting from the given 'begin' t_point, this function fills an entire zone 
by replacing characters inside with the character 'F'. A zone is an group of 
the same character delimitated horizontally and vertically by other characters
or the array boundry.
The flood_fill function won't fill diagonally.
The flood_fill function will be prototyped like this:
  void  flood_fill(char **tab, t_point size, t_point begin);
The t_point structure is prototyped like this:
  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;
Example:
$> cat test_main.c
#include "test_functions.h"
#include "flood_fill.h"
int main(void)
{
	char **area;
	t_point size = {8, 5};
	t_point begin = {2, 2};
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	}
	area = make_area(zone);
	print_tab(area);
	flood_fill(area, size, begin);
	putc('\n');
	print_tab(area);
	return (0);
}
$> gcc flood_fill.c test_main.c test_functions.c -o flood_fill; ./flood_fill
1 1 1 1 1 1 1 1
1 0 0 0 1 0 0 1
1 0 0 1 0 0 0 1
1 0 1 0 0 0 0 1
1 1 0 0 0 0 0 0
1 1 1 1 1 1 1 1
1 F F F 1 0 0 1
1 F F 1 0 0 0 1
1 F 1 0 0 0 0 1
1 1 0 0 0 0 0 0
$> 
------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct  s_point
{
  int           x;
  int           y;
}               t_point;


void fill(char **tab, t_point size, char target, int row, int col)
{
  if (row < 0 || col < 0 || row >= size.y || col >= size.x)
      return;
  if (tab[row][col] == 'F' || tab[row][col] != target)
      return;
  tab[row][col] = 'F';
  fill(tab, size, target, row -1, col);
  fill(tab, size, target, row +1, col);
  fill(tab, size, target, row, col - 1);
  fill(tab, size, target, row, col + 1);
};

void flood_fill(char **tab, t_point size, t_point begin)
{
  char target = tab[begin.y][begin.x]; 
  fill(tab, size, target, begin.y, begin.x); 
}

// Função para imprimir a matriz
void print_tab(char **tab, t_point size)
{
    for (int i = 0; i < size.y; i++)
    {
        printf("%s\n", tab[i]);
    }
}

// Função para converter `zone[]` em um array de `char**`
char **make_area(char *zone[], t_point size)
{
    char **area = (char **)malloc(size.y * sizeof(char *));
    for (int i = 0; i < size.y; i++)
    {
        area[i] = (char *)malloc(size.x * sizeof(char));
        for (int j = 0; j < size.x; j++)
        {
            area[i][j] = zone[i][j * 2]; // Ignora os espaços no array zone[]
        }
    }
    return area;
}

// Função para liberar memória da matriz
void free_area(char **area, t_point size)
{
    for (int i = 0; i < size.y; i++)
        free(area[i]);
    free(area);
}

int main(void)
{
    char **area;
    t_point size = {8, 5};
    t_point begin = {2, 2};

    char *zone[] = {
        "1 1 1 1 1 1 1 1",
        "1 0 0 0 1 0 0 1",
        "1 0 0 1 0 0 0 1",
        "1 0 1 1 0 0 0 1",
        "1 1 1 0 0 0 0 1",
    };

    area = make_area(zone, size);

    printf("Antes do Flood Fill:\n");
    print_tab(area, size);

    flood_fill(area, size, begin);

    printf("\nDepois do Flood Fill:\n");
    print_tab(area, size);

    free_area(area, size);

    return 0;
}