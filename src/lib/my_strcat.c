/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** my_strcat.c
*/

#include "defender.h"
#include <stdlib.h>

char *my_strcat(char *str, char *s2)
{
    int size = my_strlen(str) + my_strlen(s2);
    char *tmp = malloc((sizeof(char) * (size + 1)));
    int i;

    for (i = 0; str[i] != '\0'; i++)
        tmp[i] = str[i];
    for (int j = 0; s2[j] != '\0'; j++) {
        tmp[i] = s2[j];
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}