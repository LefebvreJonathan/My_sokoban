/*
** EPITECH PROJECT, 2017
** setArray.c
** File description:
** set file into array
*/

#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../include/my.h"

void set_array(char ***array, char *file)
{
	FILE *fp = fopen(file, "r");
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int size = 0;
	int lenght = 1;

	while ((read = getline(&line, &len, fp)) != -1) {
		lenght = read;
		size++;
	}
	(*array) = malloc(sizeof(char) * size * lenght + 1);
	fp = fopen(file, "r");
	for (int i = 0; i != size; i++) {
		read = getline(&line, &len, fp);
		(*array)[i] = malloc(sizeof(char) * read + 1);
		my_strcpy((*array)[i], line);
		(*array)[i + 1] = NULL;
	}
}
