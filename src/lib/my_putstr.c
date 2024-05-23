/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** display one-by-one the characters of a string
*/

#include "defender.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
