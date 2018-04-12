/*
** EPITECH PROJECT, 2017
** my_arraylen.c
** File description:
** give the length of array
*/

#include <stdlib.h>

int my_arraylen(char **av)
{
	int i = 0;

	while (av[i] != NULL)
		i++;
	return (i);
}
