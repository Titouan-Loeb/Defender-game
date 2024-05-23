/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include "defender.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (i = 0; str[i]; i++);
    return (i);
}

void usage(void)
{
    int full_size = 228 + 1;
    char *buffer = malloc(sizeof(char) * full_size);
    // int size = read(fd, buffer, full_size - 1);

    buffer[full_size] = '\0';
    my_putstr(buffer);
}

int main(int argc, char **argv, char **env)
{
    game defender;

    if (env[0] == NULL)
        return (84);
    if (argc == 2 && (argv[1][0] == '-' && argv[1][1] == 'h')) {
        usage();
        return (0);
    } else if (argc != 1)
        return (84);
    defender.wind = window();
    create_game(&defender);
    if (defender.err == 0)
        menus(&defender);
    destroy(&defender);
    return (defender.err);
}
