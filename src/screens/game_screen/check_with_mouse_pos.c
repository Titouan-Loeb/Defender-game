/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** check_with_mouse_pos.c
*/

#include "defender.h"

int is_mouse_on_tower(game *def, sfVector2i mouse, int i)
{
    if (mouse.x >= def->tower[i].pos.x + 30 &&
        mouse.x <= def->tower[i].pos.x + 120 &&
        mouse.y >= def->tower[i].pos.y + 30 &&
        mouse.y <= def->tower[i].pos.y + 120)
        return (1);
    return (0);
}

void mouse_on_defense(game *def)
{
    sfVector2i mouse;

    mouse = sfMouse_getPositionRenderWindow(def->wind);
    for (int i = 0; i < 7; i++) {
        if (is_mouse_on_tower(def, mouse, i) == 1 &&
            ((def->tower[i].rect.left / def_width) % 2) == 0 &&
            (i != 0 || def->tower[2].disp_cir == false))
            def->tower[i].rect.left += def_width;
        else if (is_mouse_on_tower(def, mouse, i) == 0 &&
            def->tower[i].rect.left / def_width % 2 == 1)
            def->tower[i].rect.left -= def_width;
        sfSprite_setTextureRect(def->tower[i].sprite,
        def->tower[i].rect);
    }
    mouse_on_button(def, mouse);
}

void spell_follow_mouse(game *def, sfVector2i mouse)
{
    mouse = sfMouse_getPositionRenderWindow(def->wind);

    if (def->fire.disp_panel && !def->fire.activated) {
        def->fire.pos.x = mouse.x - 80;
        def->fire.pos.y = mouse.y - 190;
        sfSprite_setPosition(def->fire.sprite, def->fire.pos);
    }
}