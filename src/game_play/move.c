/*
** EPITECH PROJECT, 2020
** move.c
** File description:
** move.c
*/

#include "defender.h"

void choose_direct(game *def, sfVector2f vector, int i)
{
    if (ABS(vector.x) > ABS(vector.y)) {
        if (vector.x > 0)
            def->enemy[i].rect.top = def->enemy[i].rect.height * 3;
        else
            def->enemy[i].rect.top = def->enemy[i].rect.height * 2;
    }
    else {
        if (vector.y > 0)
            def->enemy[i].rect.top = def->enemy[i].rect.height;
        else
            def->enemy[i].rect.top = 0;
    }
}

void choose_direct_golem(game *def, sfVector2f vector, int i)
{
    if (vector.x >= 0)
        def->enemy[i].rect.top = 0;
    else
        def->enemy[i].rect.top = def->enemy[i].rect.height;
}

void enemy_won(game *def, int i)
{
    if (def->enemy[i].pos.y >= 969 && def->enemy[i].life > 0) {
        if (def->enemy[i].type == golem)
            def->life.count = 0;
        else
            def->life.count -= 1;
        play_win_enemy(def, def->enemy[i]);
        check_life(def);
        def->enemy[i].life = 0;
    }
}

void move_enemy(game *def, int i)
{
    int loc = def->enemy[i].loc;
    sfVector2f big_vector = {def->map.way[loc].x - def->enemy[i].pos.x,
                            def->map.way[loc].y - def->enemy[i].pos.y};
    sfVector2f real_vector;
    double norm = sqrt(pow(big_vector.x, 2) + pow(big_vector.y, 2));
    real_vector = (sfVector2f)
    {big_vector.x * def->enemy[i].speed * def->move.sec / norm,
    big_vector.y * def->enemy[i].speed * def->move.sec / norm};
    if (ABS(real_vector.x) < ABS(big_vector.x))
        sfSprite_move(def->enemy[i].sprite, real_vector);
    else if (loc < 33)
        def->enemy[i].loc++;
    def->enemy[i].pos = sfSprite_getPosition(def->enemy[i].sprite);
    enemy_won(def, i);
    if (def->enemy[i].type != golem)
        choose_direct(def, real_vector, i);
    else
        choose_direct_golem(def, real_vector, i);
}

void move_enemies(game *def)
{
    for (int i = 0; i < def->nb_enemy.count; i++)
        move_enemy(def, i);
}
