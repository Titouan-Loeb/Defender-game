/*
** EPITECH PROJECT, 2020
** htp.c
** File description:
** htp.c
*/

#include "defender.h"

void create_htp(game *def)
{
    def->htp.disp_panel = false;
    def->htp.sprite = sfSprite_create();
    def->htp.texture = sfTexture_createFromFile("assets/htp.png", NULL);
    sfSprite_setTexture(def->htp.sprite, def->htp.texture, sfTrue);
}

void clic_htp(game *def, sfVector2i mouse)
{
    if (mouse.x >= 340 && mouse.x <= 402 &&
        mouse.y >= 998 && mouse.y <= 1060 &&
        def->htp.disp_panel == false) {
        def->htp.disp_panel = true;
        def->stop = true;
    }
    else if ((mouse.x < 419 || mouse.x > 1495 ||
        mouse.y < 101 || mouse.y > 660) &&
        def->htp.disp_panel == true) {
        def->htp.disp_panel = false;
        def->stop = false;
    }
}

void mouse_htp(game *def)
{
    sfVector2i mouse;

    mouse = sfMouse_getPositionRenderWindow(def->wind);
    if (mouse.x >= 1379 && mouse.x <= 1468 &&
        mouse.y >= 129 && mouse.y <= 211
        && def->htp.disp_panel == true)
        def->close_htp.disp_panel = true;
    else
        def->close_htp.disp_panel = false;
}

void clic_close_htp(game *def, sfVector2i mouse)
{
    if (mouse.x >= 1379 && mouse.x <= 1468 &&
        mouse.y >= 129 && mouse.y <= 211
        && def->htp.disp_panel == true)
        def->htp.disp_panel = false;
}

void create_close_htp(game *def)
{
    def->close_htp.disp_panel = false;
    def->close_htp.sprite = sfSprite_create();
    def->close_htp.texture =
    sfTexture_createFromFile("assets/close_an.png", NULL);
    sfSprite_setTexture(def->close_htp.sprite, def->close_htp.texture, sfTrue);
}