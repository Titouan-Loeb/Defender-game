/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** clic_option.c
*/

#include "defender.h"

void clic_quit_option(game *def, sfVector2i mouse)
{
    if (mouse.x >= quit_option_left && mouse.x <= quit_option_rigth &&
        mouse.y >= quit_option_top && mouse.y <= quit_option_bot)
        menus(def);
}

void clic_plus_enemy(game *def, sfVector2i mouse)
{
    if (mouse.x >= plus_enemy_left && mouse.x <= plus_enemy_rigth &&
        mouse.y >= plus_enemy_top && mouse.y <= plus_enemy_bot &&
        def->nb_wave.count < 99) {
        def->nb_wave.count += 1;
        check_nb_wave(def);
    }
}

void clic_less_enemy(game *def, sfVector2i mouse)
{
    if (mouse.x >= less_enemy_left && mouse.x <= less_enemy_rigth &&
        mouse.y >= less_enemy_top && mouse.y <= less_enemy_bot &&
        def->nb_wave.count > 1) {
        def->nb_wave.count -= 1;
        check_nb_wave(def);
    }
}

void clic_less_purcent(game *def, sfVector2i mouse)
{
    if (mouse.x >= less_purcent_left && mouse.x <= less_purcent_rigth &&
        mouse.y >= less_purcent_top && mouse.y <= less_purcent_bot &&
        def->wave_increase.count >= 20) {
        def->wave_increase.count -= 10;
        check_wave_increase(def);
    }
}

void clic_plus_purcent(game *def, sfVector2i mouse)
{
    if (mouse.x >= plus_purcent_left && mouse.x <= plus_purcent_rigth &&
        mouse.y >= plus_purcent_top && mouse.y <= plus_purcent_bot &&
        def->wave_increase.count < 100) {
        def->wave_increase.count += 10;
        check_wave_increase(def);
    }
}