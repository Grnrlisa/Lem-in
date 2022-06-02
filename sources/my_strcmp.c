/*
** EPITECH PROJECT, 2022
** init_graph.c
** File description:
** int_graph.c
*/

#include "my.h"

bool my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] && s2[i]; i++) {
        if (s1[i] != s2[i]) {
            return false;
        }
    }
    return true;
}
