/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** clic_pause_music
*/

#include "defender.h"

void clic_music_option(game *def, sfVector2i mouse)
{
    if (mouse.x >= 608 && mouse.x <= 818 &&
        mouse.y >= 245 && mouse.y <= 429 &&
        def->music_on == false) {
        def->music_on = true;
        sfMusic_play(def->music[menu_m]);
    } else if (mouse.x >= 608 && mouse.x <= 818 &&
        mouse.y >= 245 && mouse.y <= 429 && def->music_on == true) {
        def->music_on = false;
        disable_musics(def);
    }
}

void clic_sound_option(game *def, sfVector2i mouse)
{
    if (mouse.x >= 1142 && mouse.x <= 1343 &&
        mouse.y >= 245 && mouse.y <= 422 && def->sound_on == true)
        def->sound_on = false;
    else if (mouse.x >= sound_left && mouse.x <= sound_right &&
        mouse.y >= sound_top && mouse.y <= sound_bot && def->sound_on == false)
        def->sound_on = true;
}