/*
** EPITECH PROJECT, 2021
** list_void_insert_list.c
** File description:
** list_void_insertlist
*/

#include "list_void.h"

int list_void_insert_begin(list_void_t *param, void *value)
{
    node_void_t *new_nod = list_void_init_new_nod(value);

    if (param->first == 0){
        param->first = new_nod;
        return 0;
    }
    new_nod->next = param->first;
    param->first = new_nod;
    return 1;
}

int list_void_insert_end(list_void_t *list, void *value)
{
    node_void_t *new_nod = list_void_init_new_nod(value);
    node_void_t *nod_before = list_void_get_nod(list, list_void_size(list) - 1);

    if (list->first == 0){
        list->first = new_nod;
        return 0;
    }
    nod_before->next = new_nod;
    new_nod->next = 0;
    return 1;
}

int list_void_insert_at_index(list_void_t *param, void *value, int index)
{
    node_void_t *new_nod = 0;
    node_void_t *cur_nod = 0;
    node_void_t *nod_before = 0;

    if (index < 0 || index > list_void_size(param)){
        my_perror("debug error index no good\n");
        return 0;
    }
    if (index == 0){
        list_void_insert_begin(param, value);
    } else if (index == list_void_size(param)){
        new_nod = list_void_init_new_nod(value);
        nod_before = list_void_get_nod(param, index - 1);
        nod_before->next = new_nod;
    } else {
        new_nod = list_void_init_new_nod(value);
        cur_nod = list_void_get_nod(param, index);
        nod_before = list_void_get_nod(param, index - 1);
        new_nod->next = cur_nod;
        nod_before->next = new_nod;
    }
    return 1;
}
