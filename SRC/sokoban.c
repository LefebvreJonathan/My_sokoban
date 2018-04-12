/*
** EPITECH PROJECT, 2017
** sokoban
** File description:
** game sokoban
*/

#include <ncurses.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/position.h"
#include "../include/my.h"

void too_small(int line_max, int colums_max )
{
	char message[] = "Too small !!";
	
	while (LINES < line_max || COLS < colums_max) {
		clear();
		mvprintw(LINES / 2, COLS / 2 - my_strlen(message)/2, message);
		refresh();
	}
}

void putarray(char **av)
{
	for (int i = 0; av[i] != NULL; i++)
		printf("%s\n", av[i]);
}

int sokoban(char *path)
{
	int ch = 0;
	char **array;
	int colums_max = 0;
	int line_max = 0;
	struct s_position *player = malloc(sizeof(struct s_position));

	set_array(&array, path);
	colums_max = cols_max(array);
	line_max = my_arraylen(array);
	search_player(player, array, line_max, colums_max);
	initscr();
	curs_set(0);
	noecho();
	keypad(stdscr, TRUE);
	while (ch != ' ') {
		clear();
		move_player(array, player, ch);
		place_box(array, player);
		too_small(line_max, colums_max);
		for (int i = 0; i < line_max; i++)
			mvprintw((LINES / 2)  - (line_max / 2) + i,
				 (COLS / 2) - colums_max / 2, array[i]);
		refresh();
		if (end(array, player) == 0 || game_lock(array, line_max, player) == player->nbr_box) {
			break;
		}
	ch = getch();
	}
	clear();
	for (int i = my_arraylen(array); i >= 0; i--)
		free(array[i]);
	free(array);
	free(player);
	endwin();
	return (0);
}
