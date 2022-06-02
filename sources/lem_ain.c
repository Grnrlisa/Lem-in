/*
** EPITECH PROJECT, 2021
** lem_in
** File description:
** main
*/

#include "my.h"
#include "../include/lem_in.h"

int main(int argc, char **argv)
{
    if (!parameters_ok(argc, argv)) {
        return 84;
    }
    graph_t *graph = init_graph(argv[1]);
    list_void_t *path = find_path(graph);
    //moove_ants(graph, path);
    return (0);
}
