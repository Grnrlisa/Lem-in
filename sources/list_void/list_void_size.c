/*
** EPITECH PROJECT, 2022
** list_void_size.c
** File description:
** list void size
*/

#include "list_void.h"

int list_void_size(list_void_t *list)
{
    int res = 0;

    for (node_void_t *nd = list->first; nd; nd = nd->next, res++);
    return res;
}
