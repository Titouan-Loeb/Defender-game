/*
** EPITECH PROJECT, 2020
** cursor_game.c
** File description:
** cursor_game.c
*/

#include "defender.h"

void mouse_on_button(game *def, sfVector2i mouse)
{
    if (mouse.x >= wave_left && mouse.x <= wave_right &&
        mouse.y >= wave_top && mouse.y <= wave_bot)
        def->wave_button.rect = (sfIntRect){70, 0, 70, 70};
    else
        def->wave_button.rect = (sfIntRect){0, 0, 70, 70};
    sfSprite_setTextureRect(def->wave_button.sprite, def->wave_button.rect);
}