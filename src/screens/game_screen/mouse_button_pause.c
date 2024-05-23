/*
** EPITECH PROJECT, 2020
** mouse_button_pause.c
** File description:
** mouse_button_pause.c
*/

#include "defender.h"

void mouse_restart(game *def)
{
    sfVector2i mouse;

    mouse = sfMouse_getPositionRenderWindow(def->wind);
    if (mouse.x >= restart_left && mouse.x <= restart_right &&
        mouse.y >= restart_top && mouse.y <= restart_bot
        && def->pause.disp_panel == true)
            def->restart.disp_panel = true;
    else
        def->restart.disp_panel = false;
}

void mouse_quit_pause(game *def)
{
    sfVector2i mouse;

    mouse = sfMouse_getPositionRenderWindow(def->wind);
    if (mouse.x >= quit_left && mouse.x <= quit_right &&
        mouse.y >= quit_top && mouse.y <= quit_bot
        && def->pause.disp_panel == true)
            def->quit_pause.disp_panel = true;
    else
        def->quit_pause.disp_panel = false;
}

void mouse_sound(game *def)
{
    sfVector2i mouse;

    mouse = sfMouse_getPositionRenderWindow(def->wind);
    if (mouse.x >= 1048 && mouse.x <= 1257 &&
        mouse.y >= 207 && mouse.y <= 392 &&
        def->pause.disp_panel == true)
        def->sound_an.disp_panel = true;
    else if (def->pause.disp_panel == false)
        def->sound_an.disp_panel = false;
    else
        def->sound_an.disp_panel = false;
}

void mouse_close(game *def)
{
    sfVector2i mouse;

    mouse = sfMouse_getPositionRenderWindow(def->wind);
    if (mouse.x >= 1379 && mouse.x <= 1468 &&
        mouse.y >= 129 && mouse.y <= 211 &&
        def->pause.disp_panel == true)
        def->close_an.disp_panel = true;
    else
        def->close_an.disp_panel = false;
}

void mouse_music(game *def)
{
    sfVector2i mouse;

    mouse = sfMouse_getPositionRenderWindow(def->wind);
    if (mouse.x >= 676 && mouse.x <= 887 &&
        mouse.y >= 205 && mouse.y <= 391 &&
        def->pause.disp_panel == true)
        def->music_an.disp_panel = true;
    else
        def->music_an.disp_panel = false;
}