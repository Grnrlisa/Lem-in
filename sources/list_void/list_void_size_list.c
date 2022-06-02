/*
** EPITECH PROJECT, 2021
** size_list.c
** File description:
** size_list.c
*/

#include "list_void.h"
#include <stdio.h>

int size_list(list_void_t *list)
{
    node_void_t *node = list->first;
    int size = 1;

    if (list->first == NULL) {
        return 0;
    }
    for (; node->next != NULL; size++, node = node->next);
    return size;
}
