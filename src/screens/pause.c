/*
** EPITECH PROJECT, 2020
** pause.c
** File description:
** pause.c
*/

#include "defender.h"

void space_menu(game *def)
{
    if ((def->event.type == sfEvtKeyPressed
    && def->event.key.code == sfKeySpace) &&
    def->stop == false && def->lose.disp_panel == false) {
        def->pause.disp_panel = true;
        def->stop = true;
    }
    else if (def->event.type == sfEvtKeyPressed
    && def->event.key.code == sfKeySpace &&
    def->stop == true && !def->gobelin.disp_panel) {
        setup_bool_pause_false(def);
    }
}