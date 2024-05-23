/*
** EPITECH PROJECT, 2019
** window.c
** File description:
** window.c
*/

#include "defender.h"

sfRenderWindow *window(void)
{
    sfRenderWindow *wind;
    sfVideoMode video_mode;

    video_mode.width = 1920;
    video_mode.height = 1080;
    video_mode.bitsPerPixel = 32;
    wind = sfRenderWindow_create(video_mode, "MyWindow", sfFullscreen, NULL);
    return (wind);
}

void create_mouse(game *def)
{
    def->cursor.sprite = sfSprite_create();
    def->cursor.texture = sfTexture_createFromFile("assets/Cursor.png", NULL);
    sfSprite_setTexture(def->cursor.sprite, def->cursor.texture, sfTrue);
    sfRenderWindow_setMouseCursorVisible(def->wind, sfFalse);
    def->cursor.rect = (sfIntRect){0, 0, 43, 62};
    sfSprite_setTextureRect(def->cursor.sprite, def->cursor.rect);
}

void create_game2(game *def)
{
    create_defenses(def);
    create_ways(def);
    create_mouse(def);
    create_description(def);
    create_pause(def);
    create_wave_button(def);
    create_drake(def);
    create_enemies(def);
    create_fire(def);
    create_musics(def);
    create_win_lose(def);
    create_option(def);
    create_nb_wave(def);
}

void create_game(game *def)
{
    def->err = 0;
    setup_var(def);
    create_menus(def);
    create_money(def);
    create_wave_increase(def);
    create_life(def);
    create_restart(def);
    create_htp(def);
    create_htp(def);
    create_close_htp(def);
    create_wave_txt(def);
    create_wave_tot_txt(def);
    def->move.clock = sfClock_create();
    def->map.sprite = sfSprite_create();
    def->map.texture = sfTexture_createFromFile("assets/map1.png", NULL);
    if (def->map.texture == NULL)
        def->err = 84;
    sfSprite_setTexture(def->map.sprite, def->map.texture, sfTrue);
    create_game2(def);
}
