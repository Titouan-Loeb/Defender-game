/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** tower_attack.c
*/

#include "defender.h"

void launch_attack(game *def, enemies *enemy, towers *tower)
{
    (void)enemy;
    (void)def;
    char *filepath[] = {"assets/arrow.png", "assets/magic_ball.png",
                        "assets/bomb.png", "assets/rock_attack.png"};
    sfVector2f center[] = {{15, 4}, {9, 9}, {20, 20}, {10, 10}};

    tower->attacking = true;
    tower->attack.disp_panel = true;
    tower->attack.sprite = sfSprite_create();
    tower->attack.texture =
    sfTexture_createFromFile(filepath[tower->spe], NULL);
    sfSprite_setTexture(tower->attack.sprite, tower->attack.texture, sfTrue);
    sfSprite_setOrigin(tower->attack.sprite, center[tower->spe]);
    tower->attack.pos = (sfVector2f){tower->pos.x + def_width/2,
    tower->pos.y + def_height/2 - 20};
    sfSprite_setPosition(tower->attack.sprite, tower->attack.pos);
    tower->attack.clock.clock = sfClock_create();
}

void defense_attack(game *def)
{
    for (int i = 0; i < 7; i++) {
        if (def->tower[i].rect.left >= 300)
            target_enemy(def, &def->tower[i]);
        if (def->tower[i].rect.left >= 300 && def->tower[i].attacking)
            move_attack(def, &def->tower[i]);
        if (def->tower[i].attacking == true)
            end_attack(def, &def->tower[i]);
    }
}

void attack_enemy(game *def, int target, towers *tower)
{
    tower->attack.disp_panel = false;
    if (tower->spe != mortar)
        def->enemy[target].life -= tower->damage;
    else
        attack_bomb(def, tower, 80);
    if (def->enemy[target].type == golem && tower->spe == rock)
        def->enemy[target].life -= 10;
    if (def->enemy[target].type == gobelin && tower->spe == mage)
        def->enemy[target].life -= tower->damage/2;
    if (def->enemy[target].type == bandit && tower->spe == archer)
        def->enemy[target].life -= def->enemy[target].life/5;
    enemy_dead(def, target);
}

void end_attack(game *def, towers *tower)
{
    (void)def;
    tower->attack.clock.time =
    sfClock_getElapsedTime(tower->attack.clock.clock);
    tower->attack.clock.sec =
    tower->attack.clock.time.microseconds / 1000000.0;
    if (tower->attack.clock.sec > tower->delay_attack &&
        tower->attack.disp_panel == false) {
        tower->attacking = false;
        sfClock_destroy(tower->attack.clock.clock);
    }
}