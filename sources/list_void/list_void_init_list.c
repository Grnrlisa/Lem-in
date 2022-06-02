/*
** EPITECH PROJECT, 2021
** init_list.c
** File description:
** init the list
*/

#include "list_void.h"
#include <stdio.h>
#include <stdlib.h>

list_void_t *list_void_init(void)
{
    list_void_t *param = malloc(sizeof(list_void_t));

    param->first = NULL;
    return param;
}

node_void_t *list_void_init_new_nod(void *value)
{
    node_void_t *nod = malloc(sizeof(node_void_t));

    nod->elem = value;
    nod->next = NULL;
    return nod;
}
