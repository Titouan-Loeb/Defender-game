/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** refresh_texts.c
*/

#include "defender.h"

void check_nb_wave(game *def)
{
    char *score = my_nbr_to_str(def->nb_wave.count);

    sfText_setString(def->nb_wave.text, score);
}

void check_wave_increase(game *def)
{
    char *score = my_nbr_to_str(def->wave_increase.count);

    sfText_setString(def->wave_increase.text, score);
}