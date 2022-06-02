/*
** EPITECH PROJECT, 2022
** init_graph.c
** File description:
** int_graph.c
*/

#include "my.h"
#include "../include/lem_in.h"

int get_nbr_ants_room_begin(char **tab, int i)
{
    int nbr_ants = 0;

    if (i > 0 && is_start(tab[i - 1])) {
        nbr_ants = my_getnbr(tab[0]);
    }
    return nbr_ants;
}

char *get_name_room(char *str, char end)
{
    int len_name = get_len_name(str, end);
    char *res = malloc(sizeof(char) * (len_name + 1));
    int i = 0;

    for (; i != len_name; i++) {
        res[i] = str[i];
    }
    res[i] = '\0';
    return res;
}

node_room_t *init_room(char **tab, int i)
{
    node_room_t *room = malloc(sizeof(node_room_t));

    room->name = get_name_room(tab[i], ' ');
    room->list_tunnels = NULL;
    room->nbr_ant = get_nbr_ants_room_begin(tab, i);
    return room;
}

bool is_room(char *str)
{
    int nbr_space = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            nbr_space++;
        }
    }
    return nbr_space == 2;
}

list_void_t *init_list_all_room(char **tab)
{
    list_void_t *res = list_void_init();

    for (int i = 0; tab[i] != NULL; i++) {
        if (is_room(tab[i])) {
            add_info_in_list(res, tab, i);
        }
    }
    return res;
}

