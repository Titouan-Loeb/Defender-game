/*
** EPITECH PROJECT, 2020
** menus.c
** File description:
** menus.c
*/

#include "defender.h"

void menus_mouse(game *def)
{
    sfVector2i mouse;

    mouse = sfMouse_getPositionRenderWindow(def->wind);
    mouse_on_quit(def, mouse);
    mouse_on_start(def, mouse);
    mouse_on_options(def, mouse);
    mouse_on_credits(def, mouse);
    game_cursor(def);
}

void menus_on_clic(game *def)
{
    sfVector2i mouse;

    clic_sound(def);
    def->cursor.rect.left = 43;
    sfSprite_setTextureRect(def->cursor.sprite, def->cursor.rect);
    mouse = sfMouse_getPositionRenderWindow(def->wind);
    start_clic(def, mouse);
    credits_clic(def, mouse);
    options_clic(def, mouse);
    quit_clic(def, mouse);
}

void event_menu(game *def)
{
    while (sfRenderWindow_pollEvent(def->wind, &def->event)) {
        if (def->event.type == sfEvtKeyPressed
        && def->event.key.code == sfKeyEscape)
            sfRenderWindow_close(def->wind);
        if (def->event.type == sfEvtMouseButtonPressed)
            menus_on_clic(def);
        if (def->event.type == sfEvtMouseButtonReleased) {
            def->cursor.rect.left = 0;
            sfSprite_setTextureRect(def->cursor.sprite, def->cursor.rect);
        }
    }
}

void menus(game *def)
{
    setup_menu_music(def);
    while (sfRenderWindow_isOpen(def->wind)) {
        sfRenderWindow_setFramerateLimit(def->wind, 60);
        event_menu(def);
        if (def->event.type == sfEvtMouseButtonReleased) {
            def->cursor.rect.left = 0;
            sfSprite_setTextureRect(def->cursor.sprite, def->cursor.rect);
        }
        sfMusic_setLoop(def->music[0], sfTrue);
        menus_mouse(def);
        draw_menus(def);
    }
}