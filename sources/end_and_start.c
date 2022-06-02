/*
** EPITECH PROJECT, 2022
** init_graph.c
** File description:
** int_graph.c
*/

#include "my.h"
#include "../include/lem_in.h"

bool is_start(char *str)
{
    return my_strcmp(str, "##start\n");
}

bool is_end(char *str)
{
    return (my_strcmp(str, "##end\n"));
}

node_room_t *init_start(list_void_t *list, char **tab)
{
    char *name_start = NULL;

    for (int i = 0; tab[i]; i++) {
        if (i > 0 && is_start(tab[i - 1])) {
            name_start = get_name_room(tab[i], ' ');
        }
    }
    return get_room_from_name(name_start, list);
}

node_room_t *init_end(list_void_t *list, char **tab)
{
    char *name_end = NULL;

    for (int i = 0; tab[i]; i++) {
        if (i > 0 && is_end(tab[i - 1])) {
            name_end = get_name_room(tab[i], ' ');
        }
    }
    return get_room_from_name(name_end, list);
}
