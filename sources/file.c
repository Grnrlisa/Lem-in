/*
** EPITECH PROJECT, 2022
** file.c
** File description:
** extract data file
*/

#include "my.h"
#include <sys/stat.h>
#include <fcntl.h>

char *init_buff(char *fp)
{
    char *buff = NULL;
    int inft = 0;

    struct stat ststat;
    stat(fp, &ststat);
    buff = malloc(sizeof(char) * (ststat.st_size + 1));
    if ((inft = open(fp, O_RDONLY)) > 0) {
        read(inft, buff, ststat.st_size);
        buff[ststat.st_size] = '\0';
        close(inft);
    }
    return buff;
}
