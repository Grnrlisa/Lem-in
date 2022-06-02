/*
** EPITECH PROJECT, 2021
** lem_in h
** File description:
** header
*/

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include "../sources/list_void/list_void.h"


typedef struct node_room {
    int nbr_ant;
    char *name;
    list_void_t *list_tunnels;
} node_room_t;

typedef struct tunnel {
    float length;
    node_room_t *target;
} tunnel_t;

typedef struct graphh {
    node_room_t *start;
    node_room_t *end;
} graph_t;

list_void_t *find_path(graph_t *graph);
bool parameters_ok(int ac, char **av);
bool check_rooms(int i, char **inte_file);
bool check_first_line(char **inte_file);
int count_lines(char **inte_file);
graph_t *init_graph(char *fp);
int get_nbr_ants_room_begin(char **tab, int i);
char *get_name_room(char *str, char end);
node_room_t *init_room(char **tab, int i);
bool is_room(char *str);
list_void_t *init_list_all_room(char **tab);
void add_info_in_list(list_void_t *list, char **tab, int i);
bool is_start(char *str);
int get_len_name(char *str, char end);
void init_all_tunnels(list_void_t *list_room, char **tab);
void add_info_in_list(list_void_t *list, char **tab, int i);
int get_begin_tunnels(char **tab);
char *get_target(char *tab);
node_room_t *get_room_from_name(char *name, list_void_t *list_room);
node_room_t *init_end(list_void_t *list, char **tab);
node_room_t *init_start(list_void_t *list, char **tab);
void explore(graph_t *graph, list_void_t *answer, list_void_t *path);
bool can_insert_in_path(list_void_t *path, node_room_t *room);
float get_total_length(list_void_t *path);
