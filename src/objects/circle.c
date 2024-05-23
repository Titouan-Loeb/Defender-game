/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** circle.c
*/

#include "defender.h"

void upgrade_circle(game *def, int i)
{
    sfTexture_destroy(def->tower[i].circle.texture);
    def->tower[i].circle.texture =
    sfTexture_createFromFile("assets/Update_circle_t1.png", NULL);
    sfSprite_setTexture(def->tower[i].circle.sprite,
    def->tower[i].circle.texture, sfFalse);
}

void reupgrade_circle(game *def, int i)
{
    sfTexture_destroy(def->tower[i].circle.texture);
    def->tower[i].circle.texture =
    sfTexture_createFromFile("assets/Reupdate_circle_t1.png", NULL);
    sfSprite_setTexture(def->tower[i].circle.sprite,
    def->tower[i].circle.texture, sfFalse);
}

void reset_circle(game *def)
{
    for (int i = 0; i < 7; i++) {
        sfTexture_destroy(def->tower[i].circle.texture);
        def->tower[i].circle.texture =
        sfTexture_createFromFile("assets/new_first_circle.png", NULL);
        sfSprite_setTexture(def->tower[i].circle.sprite,
        def->tower[i].circle.texture, sfFalse);
    }
}

void degrade_circle(towers tower)
{
    sfTexture_destroy(tower.circle.texture);
    tower.circle.texture =
    sfTexture_createFromFile("assets/new_first_circle.png", NULL);
    sfSprite_setTexture(tower.circle.sprite, tower.circle.texture, sfFalse);
}

int is_on_sell(game *def, sfVector2i mouse, int i)
{
    if (mouse.x > def->tower[i].pos.x + sell_but_off_left + def_width/2 &&
        mouse.x < def->tower[i].pos.x + sell_but_off_right + def_width/2 &&
        mouse.y > def->tower[i].pos.y + sell_but_off_top + def_height/2 + 30 &&
        mouse.y < def->tower[i].pos.y + sell_but_off_bot + def_height/2 + 30)
        return (1);
    return (0);
}