/*
** EPITECH PROJECT, 2020
** clic_menu.c
** File description:
** clic_menu.c
*/

#include "defender.h"

void start_clic(game *def, sfVector2i mouse)
{
    if (mouse.x >= start_left && mouse.x <= start_right &&
        mouse.y >= start_top && mouse.y <= start_bot) {
        restart_game(def);
        play_game(def);
    }
}

void quit_clic(game *def, sfVector2i mouse)
{
    if (mouse.x >= quit_menu_left && mouse.x <= quit_menu_right &&
        mouse.y >= quit_menu_top && mouse.y <= quit_menu_bot)
        sfRenderWindow_close(def->wind);
}

void options_clic(game *def, sfVector2i mouse)
{
    if (mouse.x >= option_left && mouse.x <= option_rigth &&
        mouse.y >= option_top && mouse.y <= option_bot)
        option(def);
}

void credits_clic(game *def, sfVector2i mouse)
{
    if (mouse.x >= credits_left && mouse.x <= credits_right &&
        mouse.y >= credits_top && mouse.y <= credits_bot)
        credits(def);
}