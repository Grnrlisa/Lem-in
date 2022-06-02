/*
** EPITECH PROJECT, 2021
** get_nod.c
** File description:
** get_nod.c
*/

#include "list_void.h"
#include <stdio.h>

node_void_t *list_void_get_nod(list_void_t *list, int index)
{
    node_void_t *cur_nod = list->first;

    for (int i = 0; i < index && cur_nod->next != NULL; i++) {
        cur_nod = cur_nod->next;
    }
    return cur_nod;
}
