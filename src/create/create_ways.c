/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** create_ways.c
*/

#include "defender.h"

int count_words(char **points_pos)
{
    int nb_word = 0;

    for (nb_word = 0; points_pos != NULL && points_pos[nb_word] != NULL;
    nb_word++);
    return (nb_word);
}

void create_ways(game *def)
{
    char map_file[631];
    int fd = open("map_way", O_RDONLY);
    char **points_pos = NULL;
    int a = 0;

    def->map.way = malloc(sizeof(sfVector2f) * 34);
    if (fd != -1) {
        read(fd, &map_file, 630);
        points_pos = my_str_to_word_array(map_file);
        if (count_words(points_pos) != 68) {
            def->err = 84;
            return;
        }
        for (int i = 0; i < 34; i++) {
            def->map.way[i] = (sfVector2f){my_getnbr(points_pos[a]),
                                            my_getnbr(points_pos[a + 1])};
            a += 2;
        }
    }
}