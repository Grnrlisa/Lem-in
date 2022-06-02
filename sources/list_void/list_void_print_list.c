/*
** EPITECH PROJECT, 2021
** print_list.c
** File description:
** printthe list
*/

#include "list_void.h"

void list_void_print(list_void_t *list, void (* pf)(node_void_t *))
{
    my_printf("[");
    for (node_void_t *cur_nod = list->first; cur_nod; cur_nod = cur_nod->next) {
        (* pf)(cur_nod);
        if (cur_nod->next) {
            my_printf(" -> ");
        }
    }
    my_printf("]\n");
}
