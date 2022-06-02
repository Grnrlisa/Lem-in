/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** decoupe en mot uen suite
*/

#include "my.h"
#include <sys/stat.h>
#include <fcntl.h>

int buff_get_br_line(char *buff)
{
    int res = 0;

    for (int i = 0; buff[i]; i++) {
        if (buff[i] == '\n') {
            res++;
        }
    }
    return res;
}

int buff_get_nbr_row(char *buff)
{
    for (int res = 0; buff[res]; res++) {
        if (buff[res] == '\n') {
            return res;
        }
    }
    return (-1);
}

char **my_malloc_tab(int nbr_line, int len_line)
{
    char **res = malloc(sizeof(char *) * (nbr_line + 1));
    int i = 0;

    for (; i < nbr_line; i++) {
        res[i] = malloc(sizeof(char) * (len_line + 1));
    }
    res[i] = NULL;
    return res;
}

char **put_buff_in_tab(char *buff)
{
    char **tab = my_malloc_tab(buff_get_br_line(buff), 100);
    int x = 0;
    int y = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\n') {
            tab[x][y] = '\0';
            x++;
            y = 0;
        } else {
            tab[x][y] = buff[i];
            y++;
        }
    }
    return tab;
}
