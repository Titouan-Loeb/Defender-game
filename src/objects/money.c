/*
** EPITECH PROJECT, 2020
** money.c
** File description:
** money.c
*/

#include "defender.h"

void check_money(game *def)
{
    char *score = my_nbr_to_str(def->money.count);

    sfText_setString(def->money.text, score);
}

void create_money(game *def)
{
    char *score = my_nbr_to_str(def->money.count);

    def->money.font = sfFont_createFromFile("assets/font.ttf");
    def->money.text = sfText_create();
    def->money.pos.x = 217;
    def->money.pos.y = 28;
    sfText_setString(def->money.text, score);
    sfText_setFont(def->money.text, def->money.font);
    sfText_setCharacterSize(def->money.text, 10);
    sfText_setPosition(def->money.text, def->money.pos);
}