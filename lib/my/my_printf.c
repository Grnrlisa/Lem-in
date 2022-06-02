/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** printf.c
*/

#include "my.h"
#include <stdarg.h>


char simple_print(va_list list, char arg)
{
    if (arg == 's') {
        my_putstr(va_arg(list, char *));
    } if (arg == 'c') {
        my_putchar(va_arg(list, int));
    } if (arg == 'i' || arg == 'd') {
        my_put_nbr(va_arg(list, int));
    } if (arg == '%') {
        my_putchar('%');
    } if (arg == 'f') {
        my_putfloat(va_arg(list, int), 2);
    }
}

void my_printf(char *str, ...)
{
    va_list args;

    va_start(args, str);
    for (int i = 0; str[i]; i++) {
        if (str[i] == '%') {
            i++;
            simple_print(args, str[i]);
        } else
            my_putchar(str[i]);
    }
    va_end(args);
}

