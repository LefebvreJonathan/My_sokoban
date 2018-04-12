/*
1;5002;0c** EPITECH PROJECT, 2017
** my.h
** File description:
** my_sokoban
*/

#ifndef MY_H_
#define MY_H_

#include "position.h"

void move_player(char **array, struct s_position *player, int ch);
void left(char **array, struct s_position *player);
void right(char **array, struct s_position *player);
void down(char **array, struct s_position *player);
void up(char **array, struct s_position *player);
int my_arraylen(char **av);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
void count_box(char **array, int *box, int lenght, int height);
int cols_max(char **array);
int end(char **array, struct s_position *player);
void place_box(char **array, struct s_position *player);
int test(struct s_position *player, int lenght, int height);
int can_move(char ***array, int l, int h, struct s_position *player);
int game_lock(char **array, int lenght, struct s_position *player);
void research(struct s_position **player, char **array, int *move, int *i);
void search_player(struct s_position *player, char **array, int lenght, int height);
int sokoban(char *path);
void set_array(char ***array, char *file);
void my_putchar(char c);
int my_putstr(char const *str);

#endif //MY_H_
