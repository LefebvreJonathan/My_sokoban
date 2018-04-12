/*
** EPITECH PROJECT, 2017
** move
** File description:
** 
*/

#include "../include/position.h"
#include "../include/my.h"
#include <stdlib.h>
#include <ncurses.h>

void move_player(char **array, struct s_position *player, int ch)
{
	switch (ch) {
	case (KEY_UP):
		up(array, player);
		break;
	case (KEY_DOWN):
		down(array, player);
		break;
	case (KEY_RIGHT):
		right(array, player);
		break;
	case (KEY_LEFT):
		left(array, player);
		break;
	}
}

void left(char **array, struct s_position *player)
{
	if (array[player->y][player->x - 2] == 'X' &&
		(array[player->y][player->x - 3] == ' ' ||
			array[player->y][player->x - 3] == 'O')) {
		array[player->y][player->x - 3] = 'X';
		array[player->y][player->x - 2] = ' ';
	}
	if (array[player->y][player->x - 2] == ' ' ||
		array[player->y][player->x - 2] == 'O') {
		array[player->y][player->x - 2] = 'P';
		array[player->y][player->x - 1] = ' ';
		player->x -= 1;
	}
}

void right(char **array, struct s_position *player)
{
	if (array[player->y][player->x] == 'X' &&
		(array[player->y][player->x + 1] == ' ' ||
			array[player->y][player->x + 1] == 'O')) {
		array[player->y][player->x] = ' ';
		array[player->y][player->x + 1] = 'X';
	}
	if (array[player->y][player->x] == ' ' ||
		array[player->y][player->x] == 'O') {
		array[player->y][player->x] = 'P';
		array[player->y][player->x - 1] = ' ';
		player->x += 1;
	}
}

void down(char **array, struct s_position *player)
{
	if (array[player->y + 1][player->x - 1] == 'X' &&
		(array[player->y + 2][player->x - 1] == ' ' ||
			array[player->y + 2][player->x - 1] == 'O')) {
		array[player->y + 2][player->x - 1] = 'X';
		array[player->y + 1][player->x - 1] = ' ';
	}
	if (array[player->y + 1][player->x - 1] == ' ' ||
		array[player->y + 1][player->x - 1] == 'O') {
		array[player->y + 1][player->x - 1] = 'P';
		array[player->y][player->x - 1] = ' ';
		player->y += 1;
	}
}

void up(char **array, struct s_position *player)
{
	if (array[player->y - 1][player->x - 1] == 'X' &&
		(array[player->y - 2][player->x - 1] == ' ' ||
			array[player->y - 2][player->x - 1] == 'O')) {
		array[player->y - 2][player->x - 1] = 'X';
		array[player->y - 1][player->x - 1] = ' ';
	}
	if (array[player->y - 1][player->x - 1] == ' ' ||
		array[player->y - 1][player->x - 1] == 'O') {
		array[player->y - 1][player->x - 1] = 'P';
		array[player->y][player->x - 1] = ' ';
		player->y -= 1;
	}
}
