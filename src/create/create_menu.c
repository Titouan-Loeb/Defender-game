/*
** EPITECH PROJECT, 2020
** create_menu.c
** File description:
** create_menu.c
*/

#include "defender.h"

void create_start(game *def)
{
    def->start.disp_panel = false;
    def->start.sprite = sfSprite_create();
    def->start.texture = sfTexture_createFromFile("assets/start_b.png", NULL);
    sfSprite_setTexture(def->start.sprite, def->start.texture, sfTrue);
}

void create_quit(game *def)
{
    def->quit.disp_panel = false;
    def->quit.sprite = sfSprite_create();
    def->quit.texture = sfTexture_createFromFile("assets/quite_b.png", NULL);
    sfSprite_setTexture(def->quit.sprite, def->quit.texture, sfTrue);
}

void create_options(game *def)
{
    def->options.disp_panel = false;
    def->options.sprite = sfSprite_create();
    def->options.texture =
    sfTexture_createFromFile("assets/options_b.png", NULL);
    sfSprite_setTexture(def->options.sprite, def->options.texture, sfTrue);
}

void create_credits(game *def)
{
    def->credits.disp_panel = false;
    def->credits.sprite = sfSprite_create();
    def->credits.texture =
    sfTexture_createFromFile("assets/credits_b.png", NULL);
    sfSprite_setTexture(def->credits.sprite, def->credits.texture, sfTrue);
}

void create_menus(game *def)
{
    def->game_menu.sprite = sfSprite_create();
    def->game_menu.texture = sfTexture_createFromFile("assets/menu.jpg", NULL);
    sfSprite_setTexture(def->game_menu.sprite, def->game_menu.texture, sfTrue);
    create_start(def);
    create_quit(def);
    create_options(def);
    create_credits(def);
    create_back_credits(def);
}