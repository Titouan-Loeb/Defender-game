/*
** EPITECH PROJECT, 2020
** clic_win.c
** File description:
** clic_win.c
*/

#include "defender.h"

void clic_win_quit(game *def, sfVector2i mouse)
{
    if (mouse.x >= 840 && mouse.x <= 1050 &&
        mouse.y >= 700 && mouse.y <= 753 &&
        def->win.disp_panel == true) {
        setup_bool_pause_false(def);
        restart_game(def);
        menus(def);
    }
}

void clic_win_restart(game *def, sfVector2i mouse)
{
    if (mouse.x >= 869 && mouse.x <= 1027 &&
        mouse.y >= 782 && mouse.y <= 821 &&
        def->win.disp_panel == true) {
        setup_bool_pause_false(def);
        restart_game(def);
    }
}