/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** create_mod.c
*/

#include "defender.h"

void mob_position(game *def, int square, int i)
{
    if (i == 0) {
        def->enemy[i].pos.x = def->map.way[0].x + square * 30;
        def->enemy[i].pos.y = def->map.way[0].y;
    } else {
        def->enemy[i].pos.x = def->enemy[i - 1].pos.x + 5 * square + 5;
        def->enemy[i].pos.y = def->map.way[0].y;
    }
    sfSprite_setPosition(def->enemy[i].sprite, def->enemy[i].pos);
}

void create_goblin(game *def, int i)
{
    int square = 0;

    def->enemy[i].clock.clock = sfClock_create();
    def->enemy[i].sprite = sfSprite_create();
    def->enemy[i].texture =
    sfTexture_createFromFile("assets/gobelin.png", NULL);
    sfSprite_setTexture(def->enemy[i].sprite,
    def->enemy[i].texture, sfTrue);
    square = rand() % 14;
    def->enemy[i].rect = (sfIntRect){70 * square, 0, 70, 70};
    sfSprite_setTextureRect(def->enemy[i].sprite, def->enemy[i].rect);
    def->enemy[i].pos = (sfVector2f){35, 35};
    sfSprite_setOrigin(def->enemy[i].sprite, def->enemy[i].pos);
    mob_position(def, square, i);
    def->enemy[i].loc = 0;
    def->enemy[i].life = 50;
    def->enemy[i].speed = 60;
    def->enemy[i].max_square = 980;
    def->enemy[i].type = gobelin;
}

void create_wolf(game *def, int i)
{
    int square = 0;

    def->enemy[i].clock.clock = sfClock_create();
    def->enemy[i].sprite = sfSprite_create();
    def->enemy[i].texture =
    sfTexture_createFromFile("assets/wolf.png", NULL);
    sfSprite_setTexture(def->enemy[i].sprite,
    def->enemy[i].texture, sfTrue);
    square = rand() % 10;
    def->enemy[i].rect = (sfIntRect){70 * square, 0, 70, 70};
    sfSprite_setTextureRect(def->enemy[i].sprite, def->enemy[i].rect);
    def->enemy[i].pos = (sfVector2f){35, 35};
    sfSprite_setOrigin(def->enemy[i].sprite, def->enemy[i].pos);
    mob_position(def, square, i);
    def->enemy[i].loc = 0;
    def->enemy[i].life = 20;
    def->enemy[i].speed = 120;
    def->enemy[i].max_square = 700;
    def->enemy[i].type = wolf;
}

void create_bandit(game *def, int i)
{
    int square = 0;

    def->enemy[i].clock.clock = sfClock_create();
    def->enemy[i].sprite = sfSprite_create();
    def->enemy[i].texture =
    sfTexture_createFromFile("assets/bandit_.png", NULL);
    sfSprite_setTexture(def->enemy[i].sprite,
    def->enemy[i].texture, sfTrue);
    square = rand() % 12;
    def->enemy[i].rect = (sfIntRect){70 * square, 0, 70, 70};
    sfSprite_setTextureRect(def->enemy[i].sprite, def->enemy[i].rect);
    def->enemy[i].pos = (sfVector2f){35, 35};
    sfSprite_setOrigin(def->enemy[i].sprite, def->enemy[i].pos);
    mob_position(def, square, i);
    def->enemy[i].loc = 0;
    def->enemy[i].life = 100;
    def->enemy[i].speed = 44;
    def->enemy[i].max_square = 1680;
    def->enemy[i].type = bandit;
}

void create_golem(game *def, int i)
{
    int square = 0;

    def->enemy[i].clock.clock = sfClock_create();
    def->enemy[i].sprite = sfSprite_create();
    def->enemy[i].texture =
    sfTexture_createFromFile("assets/golem_.png", NULL);
    sfSprite_setTexture(def->enemy[i].sprite,
    def->enemy[i].texture, sfTrue);
    square = rand() % 12;
    def->enemy[i].rect = (sfIntRect){0, 0, 110, 110};
    sfSprite_setTextureRect(def->enemy[i].sprite, def->enemy[i].rect);
    def->enemy[i].pos = (sfVector2f){55, 55};
    sfSprite_setOrigin(def->enemy[i].sprite, def->enemy[i].pos);
    mob_position(def, square, i);
    def->enemy[i].loc = 0;
    def->enemy[i].life = 550 + 50 * def->wave_num;
    def->enemy[i].speed = 30;
    def->enemy[i].max_square = 1044;
    def->enemy[i].type = golem;
}