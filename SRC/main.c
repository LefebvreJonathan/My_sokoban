/*
** EPITECH PROJECT, 2017
** my_sokoban.c
** File description:
** 
*/


#include <ncurses.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/position.h"
#include "../include/my.h"

int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);

	if (fd == -1 || ac != 2) {
		my_putstr("Error\n");
		return (84);
	} else
		return (sokoban(av[1]));
}
