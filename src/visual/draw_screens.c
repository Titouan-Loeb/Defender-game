/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** draw_screens.c
*/

#include "defender.h"

void draw_option(game *def)
{
    sfRenderWindow_drawSprite(def->wind, def->game_menu.sprite, NULL);
    sfRenderWindow_drawSprite(def->wind, def->option.sprite, NULL);
    sfRenderWindow_drawText(def->wind, def->wave_increase.text, NULL);
    sfRenderWindow_drawText(def->wind, def->nb_wave.text, NULL);
    sfRenderWindow_drawSprite(def->wind, def->cursor.sprite, NULL);
    sfRenderWindow_display(def->wind);
}

void draw_credits(game *def)
{
    sfRenderWindow_drawSprite(def->wind, def->credits_menu.sprite, NULL);
    if (def->back_credits.disp_panel == true)
        sfRenderWindow_drawSprite(def->wind, def->back_credits.sprite, NULL);
    sfRenderWindow_drawSprite(def->wind, def->cursor.sprite, NULL);
    sfRenderWindow_display(def->wind);
}

void draw_menus(game *def)
{
    sfRenderWindow_drawSprite(def->wind, def->game_menu.sprite, NULL);
    if (def->credits.disp_panel == true)
        sfRenderWindow_drawSprite(def->wind, def->credits.sprite, NULL);
    if (def->start.disp_panel == true)
        sfRenderWindow_drawSprite(def->wind, def->start.sprite, NULL);
    if (def->quit.disp_panel == true)
        sfRenderWindow_drawSprite(def->wind, def->quit.sprite, NULL);
    if (def->options.disp_panel == true)
        sfRenderWindow_drawSprite(def->wind, def->options.sprite, NULL);
    sfRenderWindow_drawSprite(def->wind, def->cursor.sprite, NULL);
    sfRenderWindow_display(def->wind);
}