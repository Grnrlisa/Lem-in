/*
** EPITECH PROJECT, 2022
** my_perror.c
** File description:
** print sortit erreur
*/

#include "my.h"
#include <unistd.h>

void my_perror(char *str)
{
    write(2, str, my_strlen(str));
}
