/*
** EPITECH PROJECT, 2020
** wave.c
** File description:
** wave.c
*/

#include "defender.h"

void new_wave(game *def)
{
    for (int i = 0; i < def->nb_enemy.count; i++) {
        sfClock_destroy(def->enemy[i].clock.clock);
        sfSprite_destroy(def->enemy[i].sprite);
        sfTexture_destroy(def->enemy[i].texture);
    }
    def->nb_enemy.count += def->nb_enemy.count
    * def->wave_increase.count / 100;
    create_enemies(def);
}

void restart_game_wave(game *def)
{
    def->wave_num = 0;
    check_wave_txt(def);
    for (int i = 0; i < def->nb_enemy.count; i++) {
        sfClock_destroy(def->enemy[i].clock.clock);
        sfSprite_destroy(def->enemy[i].sprite);
        sfTexture_destroy(def->enemy[i].texture);
    }
    def->nb_enemy.count = 10;
    create_enemies(def);
}

void victory(game *def)
{
    if (def->wave_num >= def->nb_wave.count) {
        def->stop = true;
        def->win.disp_panel = true;
        def->clear = 0;
    }
}

void recreate_wave(game *def)
{
    int dead_enemies = 0;

    for (int i = 0; i < def->nb_enemy.count; i++) {
        if (def->enemy[i].life <= 0)
            dead_enemies++;
    }
    victory(def);
    if (dead_enemies == def->nb_enemy.count && def->clear == 0 &&
        def->wave_num < def->nb_wave.count) {
        def->wave_button.disp_panel = false;
        def->wave_num++;
        check_wave_txt(def);
        def->clear = 1;
    }
    if (def->wave_button.disp_panel == true && def->clear == 1) {
        def->clear = 0;
        new_wave(def);
    }
}