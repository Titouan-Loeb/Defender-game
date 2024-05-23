/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** win_lose.c
*/

#include "defender.h"

void is_lose(game *def)
{
    if (def->life.count <= 0) {
        def->lose.disp_panel = true;
        def->stop = true;
    }
}
