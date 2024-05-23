/*
** EPITECH PROJECT, 2020
** create3.c
** File description:
** create3.c
*/

#include "defender.h"

void create_fire(game *def)
{
    def->fire.clock.clock = sfClock_create();
    def->fire.activated = false;
    def->fire.disp_panel = false;
    def->fire.sprite = sfSprite_create();
    def->fire.texture =
    sfTexture_createFromFile("assets/meteor_good.png", NULL);
    sfSprite_setTexture(def->fire.sprite, def->fire.texture, sfTrue);
    def->fire.rect = (sfIntRect){0, 0, 160, 227};
    sfSprite_setTextureRect(def->fire.sprite, def->fire.rect);
}

void create_back_credits(game *def)
{
    def->back_credits.disp_panel = false;
    def->back_credits.sprite = sfSprite_create();
    def->back_credits.texture =
    sfTexture_createFromFile("assets/back_credits.png", NULL);
    sfSprite_setTexture(def->back_credits.sprite,
    def->back_credits.texture, sfTrue);
}

void create_musics(game *def)
{
    char *music_path[] = {"assets/menu_music.ogg", "assets/game_music.ogg",
    "assets/click.ogg", "assets/death_goblin.ogg", "assets/goblin_win.ogg",
    "assets/death_wolf.ogg", "assets/wolf_win.ogg", "assets/death_bandit.ogg",
    "assets/bandit_win.ogg", "assets/death_golem.ogg", "assets/golem_win.ogg"};

    def->music = malloc(sizeof(sfMusic *) * 11);
    for (int i = 0; i < 7; i++)
        def->music[i] = sfMusic_createFromFile(music_path[i]);
}

void create_win_lose(game *def)
{
    def->lose.disp_panel = false;
    def->lose.sprite = sfSprite_create();
    def->lose.texture = sfTexture_createFromFile("assets/defaite.png", NULL);
    sfSprite_setTexture(def->lose.sprite, def->lose.texture, sfTrue);
    def->win.disp_panel = false;
    def->win.pos.x = 450;
    def->win.pos.y = 200;
    def->win.sprite = sfSprite_create();
    def->win.texture = sfTexture_createFromFile("assets/win.png", NULL);
    sfSprite_setTexture(def->win.sprite, def->win.texture, sfTrue);
    sfSprite_setPosition(def->win.sprite, def->win.pos);
}

void create_option(game *def)
{
    def->option.sprite = sfSprite_create();
    def->option.texture = sfTexture_createFromFile("assets/options.png", NULL);
    sfSprite_setTexture(def->option.sprite, def->option.texture, sfTrue);
    def->option.disp_panel = false;
}