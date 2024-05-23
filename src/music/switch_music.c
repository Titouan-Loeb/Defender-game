/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** switch_music.c
*/

#include "defender.h"

void setup_menu_music(game *def)
{
    for (int i = 0; i < 3; i++)
        sfMusic_stop(def->music[i]);
    if (def->music_on == true)
        sfMusic_play(def->music[0]);
}

void setup_game_music(game *def)
{
    for (int i = 0; i < 3; i++)
        sfMusic_stop(def->music[i]);
    if (def->music_on == true)
        sfMusic_play(def->music[1]);
}

void disable_musics(game *def)
{
    for (int i = 0; i < 2; i++)
        sfMusic_pause(def->music[i]);
}

void disable_sounds(game *def)
{
    for (int i = 2; i < 4; i++)
        sfMusic_stop(def->music[i]);
}