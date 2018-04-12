/*
** EPITECH PROJECT, 2017
** count.c
** File description:
** 
*/

#include "../include/position.h"
#include "../include/my.h"
#include <stdio.h>

void count_box(char **array, int *box, int lenght, int height)
{
	for (int l = 1; l != lenght; l++)
		for (int h = 0; h != height + 1; h++)
			if (array[l][h] == 'X')
				(*box) += 1;
}

int cols_max(char **array)
{
	int max = 0;

	for (int i = 0; array[i] != NULL; i++)
		if (my_strlen(array[i]) > max)
			max = my_strlen(array[i]);
	return (max);
}

int end(char **array, struct s_position *player)
{
	int y = player->y_o[0];
	int x = player->x_o[0];

	for (int i = 0; i!= player->nbr_box; i++) {
		if (array[y][x - 1] != 'X')
			return (1);
		y = player->y_o[i + 1];
		x = player->x_o[i + 1];
	}
	return (0);
}

void place_box(char **array, struct s_position *player)
{
	int y = player->y_o[0];
	int x = player->x_o[0];

	for (int i = 0; i != player->nbr_box; i++) {
		if (array[y][x - 1] == ' ')
			array[y][x - 1] = 'O';
		y = player->y_o[i + 1];
		x = player->x_o[i + 1];
	}
}
