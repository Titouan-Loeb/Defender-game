/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** music.c
*/

#include "defender.h"

void play_death_enemy(game *def, enemies enemy)
{
    int sound[] = {goblin_m, wolf_m, bandit_m, golem_m};
    char *sound_path[] = {"assets/death_goblin.ogg", "assets/death_wolf.ogg",
    "assets/death_bandit.ogg", "assets/death_golem.ogg"};

    if (def->sound_on) {
        sfMusic_destroy(def->music[sound[enemy.type]]);
        def->music[sound[enemy.type]] =
        sfMusic_createFromFile(sound_path[enemy.type]);
        sfMusic_play(def->music[sound[enemy.type]]);
    }
}

void play_win_enemy(game *def, enemies enemy)
{
    int sound[] = {goblin2_m, wolf2_m, bandit2_m, golem2_m};
    char *sound_path[] = {"assets/goblin_win.ogg", "assets/wolf_win.ogg",
    "assets/bandit_win.ogg", "assets/golem_win.ogg"};

    if (def->sound_on) {
        sfMusic_destroy(def->music[sound[enemy.type]]);
        def->music[sound[enemy.type]] =
        sfMusic_createFromFile(sound_path[enemy.type]);
        sfMusic_play(def->music[sound[enemy.type]]);
    }
}