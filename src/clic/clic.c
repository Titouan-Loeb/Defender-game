/*
** EPITECH PROJECT, 2020
** clic.c
** File description:
** clic.c
*/

#include "defender.h"

void clic_description(game *def, sfVector2i mouse)
{
    if (mouse.x >= desc_left && mouse.x <= desc_right &&
        mouse.y >= desc_top && mouse.y <= desc_bot && !def->stop
        && def->lose.disp_panel == false && def->stop == false) {
        def->gobelin.disp_panel = true;
        def->stop = true;
    } else if (!(mouse.x >= desc_left && mouse.x <= desc_right &&
        mouse.y >= desc_top && mouse.y <= desc_bot) &&
        def->stop == true) {
        def->gobelin.disp_panel = false;
        def->stop = false;
    }
}

void clic_pause(game *def, sfVector2i mouse)
{
    if (mouse.x >= pause_left && mouse.x <= pause_right &&
        mouse.y >= pause_top && mouse.y <= pause_bot && def->stop == false
        && def->lose.disp_panel == false) {
        def->pause.disp_panel = true;
        def->stop = true;
    } else if ((mouse.x < pause_panel_left || mouse.x > pause_panel_right ||
        mouse.y < pause_panel_top || mouse.y > pause_panel_bot) &&
        def->pause.disp_panel == true) {
        setup_bool_pause_false(def);
    }
}

void clic_wave(game *def, sfVector2i mouse)
{
    if (mouse.x >= wave_left && mouse.x <= wave_right &&
        mouse.y >= wave_top && mouse.y <= wave_bot &&
        def->wave_button.disp_panel == false)
        def->wave_button.disp_panel = true;
}

void clic_fire(game *def, sfVector2i mouse)
{
    if (mouse.x >= fire_left && mouse.x <= fire_right &&
        mouse.y >= fire_top && mouse.y <= fire_bot &&
        def->fire.disp_panel == false) {
        def->fire.disp_panel = true;
    } else if (!(mouse.x >= fire_left && mouse.x <= fire_right &&
        mouse.y >= fire_top && mouse.y <= fire_bot) &&
        def->fire.disp_panel == true){
        def->fire.activated = true;
        sfClock_restart(def->fire.clock.clock);
    }
}

void clic_sound(game *def)
{
    if (def->sound_on == true) {
        sfMusic_destroy(def->music[clic_m]);
        def->music[clic_m] = sfMusic_createFromFile("assets/click.ogg");
        sfMusic_play(def->music[clic_m]);
    }
}
