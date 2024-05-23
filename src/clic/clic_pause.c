/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** clic_pause.c
*/

#include "defender.h"

void clic_restart(game *def, sfVector2i mouse)
{
    if (mouse.x >= restart_left && mouse.x <= restart_right &&
        mouse.y >= restart_top && mouse.y <= restart_bot) {
        setup_bool_pause_false(def);
        restart_game(def);
    }
}

void clic_quitter(game *def, sfVector2i mouse)
{
    if (mouse.x >= quit_left && mouse.x <= quit_right &&
        mouse.y >= quit_top && mouse.y <= quit_bot) {
        def->pause.disp_panel = false;
        def->stop = false;
        def->quit_pause.disp_panel = false;
        menus(def);
    }
}

void clic_music(game *def, sfVector2i mouse)
{
    if (mouse.x >= music_left && mouse.x <= music_right &&
        mouse.y >= music_top && mouse.y <= music_bot &&
        def->music_on == false) {
        def->music_on = true;
        sfMusic_play(def->music[game_m]);
    } else if (mouse.x >= music_left && mouse.x <= music_right &&
        mouse.y >= music_top && mouse.y <= music_bot && def->music_on == true) {
        def->music_on = false;
        disable_musics(def);
    }
}

void clic_on_sound(game *def, sfVector2i mouse)
{
    if (mouse.x >= sound_left && mouse.x <= sound_right &&
        mouse.y >= sound_top && mouse.y <= sound_bot && def->sound_on == true)
        def->sound_on = false;
    else if (mouse.x >= sound_left && mouse.x <= sound_right &&
        mouse.y >= sound_top && mouse.y <= sound_bot && def->sound_on == false)
        def->sound_on = true;
}

void clic_on_pause(game *def, sfVector2i mouse)
{
    clic_restart(def, mouse);
    clic_quitter(def, mouse);
    clic_music(def, mouse);
    clic_on_sound(def, mouse);
    if (mouse.x >= 1379 && mouse.x <= 1468 &&
        mouse.y >= 129 && mouse.y <= 211)
        setup_bool_pause_false(def);
}