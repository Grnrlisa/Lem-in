/*
** EPITECH PROJECT, 2022
** init_graph.c
** File description:
** int_graph.c
*/

#include "my.h"
#include "../include/lem_in.h"

static bool is_tunnels(char *str)
{
    int nbr_tir = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '-') {
            nbr_tir++;
        }
    }
    return nbr_tir == 1;
}

char *get_target(char *tab)
{
    int size_res = 0;
    char *res = NULL;
    int i = 0;

    for (; tab[i] && tab[i] != '-'; i++);
    for (;tab[i]; i++, size_res++)
        my_put_nbr(size_res);
    res = malloc(sizeof(char) * (size_res + 2));
    return res;
}

int get_begin_tunnels(char **tab)
{
    int i = 0;

    for (; tab[i]; i++) {
        if (is_tunnels(tab[i])) {
            return i;
        }
    }
    return (-1);
}

void add_info_in_list(list_void_t *list, char **tab, int i)
{
    node_room_t *room = init_room(tab, i);

    list_void_insert_end(list, room);
}

node_void_t *node_void_cpy(node_void_t *node_to_cpy)
{
    return list_void_init_new_nod(node_to_cpy->elem);
}

list_void_t *list_cpy(list_void_t *list_to_cpy)
{
    list_void_t *res = list_void_init();

    for (node_void_t *cur = list_to_cpy->first; cur; cur = cur->next) {
        list_void_insert_end(res, node_void_cpy(cur));
    }
    return (res);
}

node_room_t *room_cpy(node_room_t *room_to_cpy)
{
    node_room_t *res = malloc(sizeof(node_room_t));

    res->nbr_ant = room_to_cpy->nbr_ant;
    res->name = malloc(sizeof(char) * (my_strlen(room_to_cpy->name) + 1));
    res->list_tunnels = list_cpy(room_to_cpy->list_tunnels);
    return (res);
}

void init_all_tunnels(list_void_t *list_room, char **tab)
{
    char *name_origin = NULL;
    char *name_target = NULL;
    node_room_t *room_origin;
    node_room_t *room_target;

    printf("test 2");
    for (int i = get_begin_tunnels(tab); tab[i]; i++) {
        printf("test");
        name_origin = get_name_room(tab[i], '-');
        name_target = get_target(tab[i]);
        room_origin = get_room_from_name(name_origin, list_room);
        room_target = get_room_from_name(name_target, list_room);
        list_void_insert_end(room_origin->list_tunnels, room_cpy(room_target));
        list_void_insert_end(room_target->list_tunnels, room_cpy(room_origin));
    }
}
