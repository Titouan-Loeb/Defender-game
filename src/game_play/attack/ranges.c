/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** attack_in_zone.c
*/

#include "defender.h"

int is_in_range(game *def, enemies *enemy, int zone)
{
    sfVector2f distance = {def->fire.pos.x + 80 - enemy->pos.x,
                            def->fire.pos.y + 190 - enemy->pos.y};
    double norm = sqrt(pow(distance.x, 2) + pow(distance.y, 2));
    if (ABS(norm) <= zone)
        return (true);
    else
        return (false);
}

int is_enemy_in_range(game *def, enemies *enemy, towers *tower)
{
    (void)def;
    sfVector2f distance = {tower->pos.x + def_width/2 - enemy->pos.x,
                            tower->pos.y + def_height/2 - enemy->pos.y + 30};
    double norm = sqrt(pow(distance.x, 2) + pow(distance.y, 2));
    if (ABS(norm) <= tower->range)
        return (true);
    else
        return (false);
}

int is_in_bomb(game *def, enemies *enemy_target, enemies *enemy, int zone)
{
    (void)def;
    sfVector2f distance = {enemy_target->pos.x - enemy->pos.x,
                            enemy_target->pos.y - enemy->pos.y};
    double norm = sqrt(pow(distance.x, 2) + pow(distance.y, 2));
    if (norm <= zone)
        return (true);
    else
        return (false);
}