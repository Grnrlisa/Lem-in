/*
** EPITECH PROJECT, 2022
** init_graph.c
** File description:
** int_graph.c
*/

#include "my.h"
#include "../include/lem_in.h"

node_room_t *get_room_from_name(char *name, list_void_t *list_room)
{
    node_void_t *res = list_room->first;
    node_room_t *cur;

    for (; res; res = res->next) {
        cur = (node_room_t *)res->elem;
        if (my_strcmp(cur->name, name) == 0) {
            return cur;
        }
    }
    return NULL;
}

int get_len_name(char *str, char end)
{
    int res = 0;

    for (; str[res] && str[res] != end; res++);
    return res;
}

graph_t *init_graph(char *fp)
{
    graph_t *res = malloc(sizeof(graph_t));
    char **inte_file = put_buff_in_tab(init_buff(fp));
    list_void_t *list_all_room = init_list_all_room(inte_file);
    init_all_tunnels(list_all_room, inte_file);
    for (node_void_t *nod = list_all_room->first; nod; nod = nod->next) {
        node_room_t *cur_room = (node_room_t *)nod->elem;
        my_printf("<%s> <%i> -> ", cur_room->name, cur_room->nbr_ant);
    }

    res->start = init_start(list_all_room, inte_file);
    res->end = init_end(list_all_room, inte_file);
    return res;
}
