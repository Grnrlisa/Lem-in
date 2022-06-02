/*
** EPITECH PROJECT, 2021
** struct.h
** File description:
** struct for list
*/

#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef struct node_void
{
    void *elem;
    struct node_void *next;
} node_void_t;

typedef struct list_void
{
    node_void_t *first;
} list_void_t;

list_void_t *list_void_init(void);
int list_void_size(list_void_t *list);
int list_void_insert_begin(list_void_t *param, void *elem);
int list_void_insert_end(list_void_t *list, void *elem);
int list_void_insert_at_index(list_void_t *param, void *elem, int index);
int list_void_size(list_void_t *list);
int list_void_kill_nod(list_void_t *param, int index_to_kill, bool delete_elem);
node_void_t *list_void_get_nod(list_void_t *list, int index);
list_void_t *list_void_rev(list_void_t *list);
void list_void_print(list_void_t *list, void (* pf)(node_void_t *));
node_void_t *list_void_init_new_nod(void *value);
void my_printf(char *str, ...);
void my_perror(char *str);
