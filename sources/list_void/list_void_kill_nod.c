/*
** EPITECH PROJECT, 2021
** size_list.c
** File description:
** size of list
*/

#include "list_void.h"
#include "my.h"
#include <stdlib.h>

int real_kill_nod(list_void_t *list, int index_to_kill, bool delete_elem)
{
    node_void_t *nod_to_kill = list_void_get_nod(list, index_to_kill);
    node_void_t *nod_before = 0;

    if (index_to_kill == 0) {
        list->first = nod_to_kill->next;
    } else {
        nod_before = list_void_get_nod(list, index_to_kill - 1);
        nod_before->next = nod_before->next->next;
    }
    if (delete_elem) {
        free(nod_to_kill->elem);
    }
    free(nod_to_kill);

    return 1;
}

int list_void_kill_nod(list_void_t *list, int index_to_kill, bool delete_elem)
{
    if (index_to_kill < 0 || index_to_kill > list_void_size(list) - 1) {
        my_perror("debug error index to kill no good\n");
        return 0;
    }
    return real_kill_nod(list, index_to_kill, delete_elem);
}

