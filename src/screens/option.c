/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** option.c
*/

#include "defender.h"

void on_clic_option(game *def)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(def->wind);

    def->cursor.rect.left = 43;
    sfSprite_setTextureRect(def->cursor.sprite, def->cursor.rect);
    clic_sound(def);
    clic_quit_option(def, mouse);
    clic_plus_enemy(def, mouse);
    clic_less_enemy(def, mouse);
    clic_plus_purcent(def, mouse);
    clic_less_purcent(def, mouse);
    clic_music_option(def, mouse);
    clic_sound_option(def, mouse);
    check_wave_tot_txt(def);
}

void event_option(game *def)
{
    while (sfRenderWindow_pollEvent(def->wind, &def->event)) {
        if (def->event.type == sfEvtMouseButtonReleased) {
            def->cursor.rect.left = 0;
            sfSprite_setTextureRect(def->cursor.sprite, def->cursor.rect);
        }
        if (def->event.type == sfEvtMouseButtonPressed) {
            on_clic_option(def);
        }
    }
}

void option(game *def)
{
    while (sfRenderWindow_isOpen(def->wind)) {
        sfRenderWindow_setFramerateLimit(def->wind, 60);
        event_option(def);
        game_cursor(def);
        draw_option(def);
    }
}