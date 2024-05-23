/*
** EPITECH PROJECT, 2020
** cursor.c
** File description:
** cursor.c
*/

#include "defender.h"

void game_cursor(game *def)
{
    sfVector2i mouse_pos;
    sfVector2f tmp;

    mouse_pos = sfMouse_getPositionRenderWindow(def->wind);
    tmp.x = mouse_pos.x - 10;
    tmp.y = mouse_pos.y - 10;
    sfSprite_setPosition(def->cursor.sprite, tmp);
}

void mouse_on_credits(game *def, sfVector2i mouse)
{
    if (mouse.x >= credits_left && mouse.x <= credits_right &&
        mouse.y >= credits_top && mouse.y <= credits_bot)
        def->credits.disp_panel = true;
    else
        def->credits.disp_panel = false;
}

void mouse_on_start(game *def, sfVector2i mouse)
{
    if (mouse.x >= start_left && mouse.x <= start_right &&
        mouse.y >= start_top && mouse.y <= start_bot)
        def->start.disp_panel = true;
    else
        def->start.disp_panel = false;
}

void mouse_on_quit(game *def, sfVector2i mouse)
{
    if (mouse.x >= quit_menu_left && mouse.x <= quit_menu_right &&
        mouse.y >= quit_menu_top && mouse.y <= quit_menu_bot)
        def->quit.disp_panel = true;
    else
        def->quit.disp_panel = false;
}

void mouse_on_options(game *def, sfVector2i mouse)
{
    if (mouse.x >= option_left && mouse.x <= option_rigth &&
        mouse.y >= option_top && mouse.y <= option_bot)
        def->options.disp_panel = true;
    else
        def->options.disp_panel = false;
}