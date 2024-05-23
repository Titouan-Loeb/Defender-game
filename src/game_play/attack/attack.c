/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** attack.c
*/

#include "defender.h"

void enemy_dead(game *def, int i)
{
    if (def->enemy[i].life <= 0) {
        play_death_enemy(def, def->enemy[i]);
        check_money(def);
        if (def->wave_num * def->wave_increase.count / 30 >= 9)
            def->money.count += 3;
        else
            def->money.count += 12 - def->wave_num *
            def->wave_increase.count / 30;
    }
}

void target_enemy(game *def, towers *tower)
{
    for (int i = 0; i < def->nb_enemy.count; i++) {
        if (is_enemy_in_range(def, &def->enemy[i], tower) == true &&
            tower->attacking == false && def->enemy[i].life > 0) {
            launch_attack(def, &def->enemy[i], tower);
            tower->target = i;
            break;
        }
    }
}

void attack_bomb(game *def, towers *tower, int zone)
{
    for (int i = 0; i < def->nb_enemy.count; i++)
        if (is_in_bomb(def, &def->enemy[tower->target],
            &def->enemy[i], zone)) {
            def->enemy[i].life -= tower->damage;
            enemy_dead(def, i);
        }
}

void attack_in_zone(game *def, int zone)
{
    for (int i = 0; i < def->nb_enemy.count; i++)
        if (is_in_range(def, &def->enemy[i], zone)) {
            def->enemy[i].life -= 70;
            enemy_dead(def, i);
        }
}

void get_move_delta_t(game *def)
{
    def->move.time = sfClock_getElapsedTime(def->move.clock);
    def->move.sec = def->move.time.microseconds / 1000000.0;
    sfClock_restart(def->move.clock);
}