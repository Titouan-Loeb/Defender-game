/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** attack_movement.c
*/

#include "defender.h"

void set_attack_angle(towers *tower, sfVector2f real_vect)
{
    int angle = 0;

    angle = RTD(atan(real_vect.x / real_vect.y)) + 90;
    if ((real_vect.x >= 0 && real_vect.y < 0) ||
        (real_vect.x < 0 && real_vect.y < 0))
        angle += 180;
    sfSprite_setRotation(tower->attack.sprite, - angle);
}

void move_attack(game *def, towers *tower)
{
    int target = tower->target;
    float delta_t = def->move.sec;
    sfVector2f e_pos = sfSprite_getPosition(def->enemy[target].sprite);
    sfVector2f a_pos = sfSprite_getPosition(tower->attack.sprite);
    sfVector2f big_vect = (sfVector2f){e_pos.x - a_pos.x,
    e_pos.y - a_pos.y};
    double norm = sqrt(pow(big_vect.x, 2) + pow(big_vect.y, 2));
    sfVector2f real_vect = (sfVector2f){big_vect.x * 350 * delta_t / norm,
    big_vect.y * 350 * delta_t / norm};

    if (ABS(real_vect.x) < ABS(big_vect.x)) {
        set_attack_angle(tower, real_vect);
        sfSprite_move(tower->attack.sprite, real_vect);
    } else if (tower->attack.disp_panel == true)
        attack_enemy(def, target, tower);
    if (def->enemy[target].life <= 0)
        tower->attack.disp_panel = false;
}