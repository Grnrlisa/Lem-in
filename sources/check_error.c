/*
** EPITECH PROJECT, 2022
** check_error.c
** File description:
** check_error.c
*/

#include "my.h"
#include "../include/lem_in.h"

bool parameters_ok(int ac, char **av)
{
    int nb_lines = 0;

    if (ac != 2)
        return false;
    char **inte_file = put_buff_in_tab(init_buff(av[1]));
    if (!check_first_line(inte_file))
        return false;
    nb_lines = count_lines(inte_file);
    for (int i = 0; i != nb_lines; i++) {
        if (!check_rooms(i, inte_file))
            return false;
    }
    return true;
}
