/*
** EPITECH PROJECT, 2022
** temp.c
** File description:
** temp
*/

#include "list_void.h"
#include <stdio.h>
#include <stdlib.h>

char *extract_word(char *input)
{
    char *res = NULL;
    int size = 0;

    for (int i = 0; input[i] && input[i] != ' '; i++, size++);
    res = malloc(sizeof(char) * (size + 1));
    for (int i = 0; i < size; i++) {
        res[i] = input[i];
    }
    return res;
}
