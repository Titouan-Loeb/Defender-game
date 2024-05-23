/*
** EPITECH PROJECT, 2020
** create2.c
** File description:
** create2.c
*/

#include "defender.h"

void create_enemies(game *def)
{
    void (*create_opponent[])(game *, int) = {create_goblin, create_wolf,
    create_bandit, create_golem};

    srand(rand() % rand());
    def->enemy = malloc(sizeof(enemies) * def->nb_enemy.count);
    for (int i = 0; i < def->nb_enemy.count; i++) {
        if (i == 0 && def->wave_num == def->nb_wave.count - 1)
            create_opponent[3](def, i);
        else
            create_opponent[rand() % 3](def, i);
    }
}

void create_drake(game *def)
{
    def->drake.clock.clock = sfClock_create();
    def->drake.sprite = sfSprite_create();
    def->drake.texture =
    sfTexture_createFromFile("assets/dragon_gif.png", NULL);
    sfSprite_setTexture(def->drake.sprite, def->drake.texture, sfTrue);
    def->drake.pos = (sfVector2f){136, 392};
    sfSprite_setPosition(def->drake.sprite, def->drake.pos);
    def->drake.rect = (sfIntRect){0, 0, 120, 100};
    sfSprite_setTextureRect(def->drake.sprite, def->drake.rect);
    def->drake.disp_panel = true;
    def->fly_drake.clock.clock = sfClock_create();
    def->fly_drake.sprite = sfSprite_create();
    def->fly_drake.texture =
    sfTexture_createFromFile("assets/fly_drake.png", NULL);
    sfSprite_setTexture(def->fly_drake.sprite, def->fly_drake.texture, sfTrue);
    def->fly_drake.disp_panel = false;
    def->fly_drake.rect = (sfIntRect){0, 0, 500, 500};
    sfSprite_setTextureRect(def->fly_drake.sprite, def->fly_drake.rect);
    def->fly_drake.pos = (sfVector2f){-205, 230};
    sfSprite_setPosition(def->fly_drake.sprite, def->fly_drake.pos);
}

void create_pause(game *def)
{
    def->pause.disp_panel = false;
    def->pause.sprite = sfSprite_create();
    def->pause.texture = sfTexture_createFromFile("assets/pause.png", NULL);
    sfSprite_setTexture(def->pause.sprite, def->pause.texture, sfTrue);
}

void create_wave_button(game *def)
{
    def->wave_button.disp_panel = false;
    def->wave_button.sprite = sfSprite_create();
    def->wave_button.texture =
    sfTexture_createFromFile("assets/wave_button.png", NULL);
    sfSprite_setTexture(def->wave_button.sprite,
    def->wave_button.texture, sfTrue);
    def->wave_button.pos.x = 1820;
    def->wave_button.pos.y = 270;
    sfSprite_setPosition(def->wave_button.sprite, def->wave_button.pos);
    def->wave_button.rect = (sfIntRect){0, 0, 70, 70};
    sfSprite_setTextureRect(def->wave_button.sprite, def->wave_button.rect);
}

void create_description(game *def)
{
    def->gobelin.disp_panel = false;
    def->gobelin.sprite_des = sfSprite_create();
    def->gobelin.texture_des =
    sfTexture_createFromFile("assets/Pedia_mob_Goblin.png", NULL);
    sfSprite_setTexture(def->gobelin.sprite_des,
    def->gobelin.texture_des, sfTrue);
    def->gobelin.pos_des.x = 1740;
    def->gobelin.pos_des.y = 1015;
    sfSprite_setPosition(def->gobelin.sprite_des, def->gobelin.pos_des);
    def->gobelin.panel_sprite = sfSprite_create();
    def->gobelin.panel_texture =
    sfTexture_createFromFile("assets/Goblin_desc.png", NULL);
    sfSprite_setTexture(def->gobelin.panel_sprite,
    def->gobelin.panel_texture, sfTrue);
    def->gobelin.panel_pos.x = 150;
    def->gobelin.panel_pos.y = 100;
    sfSprite_setPosition(def->gobelin.panel_sprite, def->gobelin.panel_pos);
}