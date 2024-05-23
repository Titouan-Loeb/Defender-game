/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** event_game_screen.c
*/

#include "defender.h"

void clic_when_unpause(game *def, sfVector2i mouse)
{
    upgrade_defense(def, mouse);
    choose_defense_type(def, mouse);
    clic_wave(def, mouse);
    clic_fire(def, mouse);
    clic_drake(def, mouse);
    clic_htp(def, mouse);
    sell_defense(def, mouse);
}

void on_clic2(game *def, sfVector2i mouse)
{
    if (def->win.disp_panel == true) {
        clic_win_restart(def, mouse);
        clic_win_quit(def, mouse);
    }
    if (def->pause.disp_panel == true)
        clic_on_pause(def, mouse);
    if (def->htp.disp_panel == true)
        clic_close_htp(def, mouse);
    clic_circle(def, mouse);
}

void on_clic(game *def)
{
    sfVector2i mouse;

    clic_sound(def);
    def->cursor.rect.left = 43;
    sfSprite_setTextureRect(def->cursor.sprite, def->cursor.rect);
    mouse = sfMouse_getPositionRenderWindow(def->wind);
    clic_pause(def, mouse);
    clic_description(def, mouse);
    if (!def->stop && def->life.count > 0)
        clic_when_unpause(def, mouse);
    if (def->lose.disp_panel == true) {
        clic_lose_restart(def, mouse);
        clic_lose_quit(def, mouse);
    }
    on_clic2(def, mouse);
}

void release_clic(game *def)
{
    sfVector2i mouse;

    def->cursor.rect.left = 0;
    sfSprite_setTextureRect(def->cursor.sprite, def->cursor.rect);
    mouse = sfMouse_getPositionRenderWindow(def->wind);
    if ((mouse.x < fire_left || mouse.x > fire_right ||
        mouse.y < fire_top || mouse.y > fire_bot) &&
        def->fire.activated == false && def->fire.disp_panel)
        def->fire.activated = true;
}

void event_game(game *def)
{
    while (sfRenderWindow_pollEvent(def->wind, &def->event)) {
        if (def->event.type == sfEvtKeyPressed
            && def->event.key.code == sfKeyEscape &&
            def->lose.disp_panel == false && !def->stop) {
            def->pause.disp_panel = true;
            def->stop = true;
        } else if (def->event.type == sfEvtKeyPressed
        && def->event.key.code == sfKeyEscape &&
        !(def->lose.disp_panel == false && !def->stop)) {
            def->pause.disp_panel = false;
            def->stop = false;
        }
        if (def->event.type == sfEvtMouseButtonPressed)
            on_clic(def);
        if (def->event.type == sfEvtMouseButtonReleased)
            release_clic(def);
        space_menu(def);
    }
}