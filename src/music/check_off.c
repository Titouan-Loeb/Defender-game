/*
** EPITECH PROJECT, 2020
** check_off.c
** File description:
** check_off.c
*/

#include "defender.h"

void check_sound_off(game *def)
{
    if (def->pause.disp_panel == true &&
        def->sound_on == false)
        def->sound_an.disp_off = true;
    if (def->pause.disp_panel == true &&
        def->sound_on == true)
        def->sound_an.disp_off = false;
    if (def->pause.disp_panel == false)
        def->sound_an.disp_off = false;
}

void check_music_off(game *def)
{
    if (def->pause.disp_panel == true &&
        def->music_on == false)
        def->music_an.disp_off = true;
    if (def->pause.disp_panel == true &&
        def->music_on == true)
        def->music_an.disp_off = false;
    if (def->pause.disp_panel == false)
        def->music_an.disp_off = false;
}