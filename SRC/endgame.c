/*
** EPITECH PROJECT, 2017
** endgame.c
** File description:
** stop the game if any box can't move
*/

#include "ncurses.h"
#include "../include/position.h"

int test(struct s_position *player, int lenght, int height)
{
	for (int i = 0; player->y_o[i] != 0; i++) {
		if (player->y_o[i] == lenght && player->x_o[i] == height)
			return (1);
	}
	return (0);
}

int can_move(char ***array, int l, int h, struct s_position *player)
{
	if ((*array)[l][h] == 'X') {
		if ((((*array)[l][h - 1] == '#' || (*array)[l][h + 1] == '#') &&
			((*array)[l - 1][h] == '#' ||
				(*array)[l + 1][h] == '#')) &&
			test(player, l, h) == 0)
			return (1);
	}
	return (0);
}

int game_lock(char **array, int lenght, struct s_position *player)
{
	int result = 0;

	for (int l = 1; l != lenght; l++) {
		for (int h = 0; array[l][h] != 0; h++)
			result += can_move(&array, l, h, player);
	}
	return (result);
}
