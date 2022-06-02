/*
** EPITECH PROJECT, 2022
** rev_list.c
** File description:
** rev the list
*/

#include "list_void.h"

list_void_t *list_void_rev(list_void_t *la)
{
    list_void_t *res = list_void_init();

    for (node_void_t *nod = la->first; nod; nod = nod->next) {
        list_void_insert_begin(res, nod->elem);
    }
    return (res);
}
