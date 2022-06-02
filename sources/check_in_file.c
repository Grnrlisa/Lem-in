/*
** EPITECH PROJECT, 2022
** check_error.c
** File description:
** check_error.c
*/

#include "my.h"
#include "../include/lem_in.h"

int count_lines(char **inte_file)
{
    int nbr_lines = 0;
    for (nbr_lines; inte_file[nbr_lines]; nbr_lines++);
    return nbr_lines;
}

bool check_first_line(char **inte_file)
{
    for (int i = 0; inte_file[0][i] != '\0'; i++) {
        if (isnum(inte_file[0][i]) == 0)
            return false;
    }
    return true;
}

bool check_rooms_annex_uwu(int i, int j, char **inte_file, int index)
{
    if (inte_file[i][j] == ' ') {
        index = j;
        for (; inte_file[i][index] != '\0'; index++) {
            if (isnum(inte_file[i][index]) == 0 && inte_file[i][index] != ' ')
                return false;
        }
    }
    return true;
}

bool check_rooms(int i, char **inte_file)
{
    int index = 0;

    if (inte_file[i][0] != '#') {
        for (int j = 0; inte_file[i][j] != '\0'; j++)
            if (!check_rooms_annex_uwu(i, j, inte_file, index))
                return false;
    }
    return true;
}
