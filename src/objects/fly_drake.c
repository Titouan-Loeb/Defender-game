/*
** EPITECH PROJECT, 2020
** fly_drake.c
** File description:
** fly_drake.c
*/

#include "defender.h"

void clic_drake(game *def, sfVector2i mouse)
{
    if (mouse.x >= fly_darke_left && mouse.x <= fly_darke_right &&
        mouse.y >= fly_darke_top && mouse.y <= fly_darke_bot) {
            def->drake.disp_panel = false;
            def->fly_drake.disp_panel = true;
        }
}

int square_fly_drake(sfIntRect *rect, int size, int max)
{
    rect->left += size;
    if (rect->left == max)
        rect->left = 4000;
    return 0;
}

void fly_drake(game *def)
{
    sfVector2f vector = {120 * def->move.sec, 30 * def->move.sec};

    if (def->fly_drake.disp_panel == true) {
        if (def->fly_drake.rect.left > 1000)
            sfSprite_move(def->fly_drake.sprite, vector);
        def->fly_drake.clock.time =
        sfClock_getElapsedTime(def->fly_drake.clock.clock);
        def->fly_drake.clock.sec =
        def->fly_drake.clock.time.microseconds / 1000000.0;
        if (def->fly_drake.clock.sec > 0.10) {
            square_fly_drake(&def->fly_drake.rect, 500, 8000);
            sfSprite_setTextureRect(def->fly_drake.sprite, def->fly_drake.rect);
            sfClock_restart(def->fly_drake.clock.clock);
        }
    }
}