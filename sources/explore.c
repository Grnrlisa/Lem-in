/*
** EPITECH PROJECT, 2022
** find_path.c
** File description:
** find the only shortest path
*/

#include "../include/lem_in.h"

void list_void_erase_all(list_void_t *list)
{
    node_void_t* current = list->first;
    node_void_t* next = 0;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}

void list_void_copy_all(list_void_t *path, list_void_t *answer)
{
    list_void_erase_all(path);
    node_void_t *nod = NULL;

    for (int i = list_void_size(answer); i > 0;
        nod = list_void_get_nod(answer, i), i--) {
        list_void_insert_end(answer, nod->elem);
    }
}

node_void_t *list_void_get_last(list_void_t *list)
{
    node_void_t *res = list->first;

    for (; res; res = res->next);
    return res;
}

void list_void_remove_last(list_void_t *list)
{
    node_void_t *nod_to_erase = list_void_get_last(list);
    node_void_t *nod_before = list_void_get_nod(list, list_void_size(list) - 1);

    free(nod_to_erase);
    nod_before->next = NULL;
}

bool list_void_is_empty(list_void_t *answer)
{
    return (!answer->first);
}

void explore(graph_t *graph, list_void_t *answer, list_void_t *path)
{
    node_room_t *current = (node_room_t *)(list_void_get_last(path)->elem);
    node_room_t *next;

    for (node_void_t *nod = current->list_tunnels->first; nod; nod = nod->next) {
        next = (node_room_t *)nod->elem;
        if (next == graph->end) {
            if (list_void_is_empty(answer)) {
                list_void_copy_all(path, answer);
                list_void_insert_end(answer, next);
            } else {
                list_void_insert_end(path, next);
                if (get_total_length(answer) > get_total_length(path)) {
                    list_void_copy_all(path, answer);
                }
                list_void_remove_last(path);
            }
        } else {
            if (can_insert_in_path(path, next)) {
                list_void_insert_end(path, next);
                explore(graph, answer, path);
                list_void_remove_last(path);
            }
        }
    }
}
