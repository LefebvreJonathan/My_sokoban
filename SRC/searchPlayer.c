/*
** EPITECH PROJECT, 2017
** searchPlayer.c
** File description:
** function who search player
*/

#include "../include/position.h"
#include "../include/my.h"
#include <stdlib.h>

void search_player(struct s_position *player, char **array, int lenght,
	int height)
{
	int i = 0;

	count_box(array, &player->nbr_box, lenght, height);
	player->x_o = malloc(sizeof(int) * player->nbr_box);
	player->y_o = malloc(sizeof(int) * player->nbr_box);
	for (int l = 1; l != lenght; l++)
		for (int h = 0; h != height + 1; h++)
			if (array[l][h] == 'P') {
				player->x = h + 1;
				player->y = l;
			} else if (array[l][h] == 'O') {
				player->x_o[i] = h + 1;
				player->y_o[i] = l;
				i++;
			}
}

