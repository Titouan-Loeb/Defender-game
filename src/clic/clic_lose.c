/*
** EPITECH PROJECT, 2020
** clic_lose.c
** File description:
** clic_lose.c
*/

#include "defender.h"

void clic_lose_restart(game *def, sfVector2i mouse)
{
    if (mouse.x >= 499 && mouse.x <= 897 &&
        mouse.y >= 768 && mouse.y <= 900 &&
        def->lose.disp_panel == true) {
        setup_bool_pause_false(def);
        restart_game(def);
    }
}

void clic_lose_quit(game *def, sfVector2i mouse)
{
    if (mouse.x >= 1031 && mouse.x <= 1433 &&
        mouse.y >= 769 && mouse.y <= 900 &&
        def->lose.disp_panel == true) {
        setup_bool_pause_false(def);
        restart_game(def);
        menus(def);
    }
}