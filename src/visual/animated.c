/*
** EPITECH PROJECT, 2020
** animated.c
** File description:
** animated.c
*/

#include "defender.h"

int square(sfIntRect *rect, int size, int max)
{
    rect->left += size;
    if (rect->left >= max)
        rect->left = 0;
    return 0;
}

void animated_drake(game *def)
{
    def->drake.clock.time = sfClock_getElapsedTime(def->drake.clock.clock);
    def->drake.clock.sec = def->drake.clock.time.microseconds / 1000000.0;
    if (def->drake.clock.sec > 0.13) {
        square(&def->drake.rect, 120, 2400);
        sfSprite_setTextureRect(def->drake.sprite, def->drake.rect);
        sfClock_restart(def->drake.clock.clock);
    }
}

void animated_gobelin(game *def)
{
    for (int i = 0; i < def->nb_enemy.count; i++) {
        def->enemy[i].clock.time =
        sfClock_getElapsedTime(def->enemy[i].clock.clock);
        def->enemy[i].clock.sec =
        def->enemy[i].clock.time.microseconds / 1000000.0;
        if (def->enemy[i].clock.sec > 0.15) {
            square(&def->enemy[i].rect, def->enemy[i].rect.width,
            def->enemy[i].max_square);
            sfSprite_setTextureRect(def->enemy[i].sprite, def->enemy[i].rect);
            sfClock_restart(def->enemy[i].clock.clock);
        }
    }
}

void animated_fire(game *def)
{
    def->fire.clock.time = sfClock_getElapsedTime(def->fire.clock.clock);
    def->fire.clock.sec = def->fire.clock.time.microseconds / 1000000.0;
    if (def->fire.activated && def->fire.clock.sec > 0.08) {
        def->fire.rect.left += 160;
        if (def->fire.rect.left == 480)
            attack_in_zone(def, 100);
        if (def->fire.rect.left < 1440)
            sfClock_restart(def->fire.clock.clock);
        if (def->fire.clock.sec > 15 && def->fire.rect.left > 1440) {
            def->fire.disp_panel = false;
            def->fire.activated = false;
            def->fire.rect.left = 0;
            sfClock_restart(def->fire.clock.clock);
        }
        sfSprite_setTextureRect(def->fire.sprite, def->fire.rect);
    }
}