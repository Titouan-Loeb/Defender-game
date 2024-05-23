/*
** EPITECH PROJECT, 2020
** create_menu.c
** File description:
** create_menu.c
*/

#include "defender.h"

void create_quit_pause(game *def)
{
    def->quit_pause.sprite = sfSprite_create();
    def->quit_pause.texture =
    sfTexture_createFromFile("assets/quit_an.png", NULL);
    sfSprite_setTexture(def->quit_pause.sprite,
                        def->quit_pause.texture, sfTrue);
    def->quit_pause.disp_panel = false;
}

void create_music_an(game *def)
{
    def->music_an.sprite = sfSprite_create();
    def->music_an.texture =
    sfTexture_createFromFile("assets/music_an.png", NULL);
    sfSprite_setTexture(def->music_an.sprite, def->music_an.texture, sfTrue);
    def->music_an.disp_panel = false;
    def->music_an.off_sp = sfSprite_create();
    def->music_an.off_text = sfTexture_createFromFile("assets/music_off_an.png",
                                                    NULL);
    sfSprite_setTexture(def->music_an.off_sp, def->music_an.off_text, sfTrue);
    def->music_an.disp_off = false;
}

void create_sound_an(game *def)
{
    def->sound_an.sprite = sfSprite_create();
    def->sound_an.texture =
    sfTexture_createFromFile("assets/sound_an.png",  NULL);
    sfSprite_setTexture(def->sound_an.sprite, def->sound_an.texture, sfTrue);
    def->sound_an.disp_panel = false;
    def->sound_an.off_sp = sfSprite_create();
    def->sound_an.off_text = sfTexture_createFromFile("assets/sound_off_an.png",
                                                    NULL);
    sfSprite_setTexture(def->sound_an.off_sp, def->sound_an.off_text, sfTrue);
    def->sound_an.disp_off = false;
}

void create_close(game *def)
{
    def->close_an.sprite = sfSprite_create();
    def->close_an.texture =
    sfTexture_createFromFile("assets/close_an.png", NULL);
    sfSprite_setTexture(def->close_an.sprite, def->close_an.texture, sfTrue);
    def->close_an.disp_panel = false;
}

void create_restart(game *def)
{
    create_close(def);
    create_sound_an(def);
    create_music_an(def);
    create_quit_pause(def);
    def->restart.sprite = sfSprite_create();
    def->restart.texture =
    sfTexture_createFromFile("assets/restart_an.png", NULL);
    sfSprite_setTexture(def->restart.sprite, def->restart.texture, sfTrue);
    def->restart.disp_panel = false;
}