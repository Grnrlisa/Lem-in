/*
** EPITECH PROJECT, 2022
** find_path.c
** File description:
** find the only shortest path
*/

#include "../include/lem_in.h"

//  bool explore_others(list_void_t *path, node_room_t *cur_room, graph_t *graph)
//  {
//      list_void_insert_end(path, cur_room);
//      return explore(graph, cur_room, path);
//  }

bool can_insert_in_path(list_void_t *path, node_room_t *room)
{
    for (node_void_t *nod = path->first; nod; nod = nod->next) {
        if (room == nod->elem) {
            return false;
        }
    }
    return true;
}

float get_total_length(list_void_t *path)
{
    float res = 0;

    for (node_void_t *nod = path->first; nod; nod = nod->next) {
        tunnel_t *tun = nod->elem;
        res += tun->length;
    }
    return res;
}

list_void_t *find_path(graph_t *graph)
{
    list_void_t *path = list_void_init();
    list_void_t *answer;

    list_void_insert_end(path, graph->start);
    answer = list_void_init();
    explore(graph, answer, path);
    return path;
}
