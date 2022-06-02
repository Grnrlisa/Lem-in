/*
** EPITECH PROJECT, 2021
** B-CPE-110-REN-1-1-BSQ-lisa.garnier
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>

int my_compute_power_rec (int nb, int p);
int my_compute_square_root (int nb);
int my_getnbr(char const *str);
int my_isneg (int n);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
char *my_strcat(char *dest, char *arg);
char **my_str_to_word_array(char *str);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strlowcase (char *str);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strupcase (char *str);
void my_swap(int *a, int *b);
int my_conv_bases(int nb, char *conv);
char *my_itoa(int nb);
int my_atoi(char const *str);
unsigned int my_unsigned(unsigned int nb);
void my_printf(char *str, ...);
char **my_str_twa(char const *str, char c);
char *init_buff(char *fp);
int isnum(char c);
void my_perror(char *str);
void my_putfloat(float nb, int nafcoma);
void my_printf(char *str, ...);
void my_putfloat(float nb, int nafcoma);
char **put_buff_in_tab(char *buff);
bool my_strcmp(char const *s1, char const *s2);

#endif/* !MY_H_ */
