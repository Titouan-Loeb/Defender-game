/*
** EPITECH PROJECT, 2020
** credits.c
** File description:
** credits.c
*/

#include "defender.h"

void credits_back_mouse(game *def, sfVector2i mouse)
{
    if (mouse.x >= 458 && mouse.x <= 616 &&
        mouse.y >= 760 && mouse.y <= 852)
        def->back_credits.disp_panel = true;
    else
        def->back_credits.disp_panel = false;
}

void credits_mouse(game *def)
{
    sfVector2i mouse;

    mouse = sfMouse_getPositionRenderWindow(def->wind);
    game_cursor(def);
    credits_back_mouse(def, mouse);
}

void create_credits_menu(game *def)
{
    def->credits_menu.sprite = sfSprite_create();
    def->credits_menu.texture =
    sfTexture_createFromFile("assets/credits.jpg", NULL);
    sfSprite_setTexture(def->credits_menu.sprite,
    def->credits_menu.texture, sfTrue);
}

void credits_on_clic(game *def)
{
    sfVector2i mouse;

    def->cursor.rect.left = 43;
    sfSprite_setTextureRect(def->cursor.sprite, def->cursor.rect);
    clic_sound(def);
    mouse = sfMouse_getPositionRenderWindow(def->wind);
    if (mouse.x >= 458 && mouse.x <= 616 &&
        mouse.y >= 760 && mouse.y <= 852)
        menus(def);
}

void credits(game *def)
{
    create_credits_menu(def);
    while (sfRenderWindow_isOpen(def->wind)) {
        sfRenderWindow_setFramerateLimit(def->wind, 60);
        while (sfRenderWindow_pollEvent(def->wind, &def->event)) {
            if (def->event.type == sfEvtKeyPressed
            && def->event.key.code == sfKeyEscape)
                sfRenderWindow_close(def->wind);
            if (def->event.type == sfEvtMouseButtonPressed)
                credits_on_clic(def);
            if (def->event.type == sfEvtMouseButtonReleased) {
                def->cursor.rect.left = 0;
                sfSprite_setTextureRect(def->cursor.sprite, def->cursor.rect);
            }
        }
        credits_mouse(def);
        draw_credits(def);
    }
}
