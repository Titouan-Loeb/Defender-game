/*
** EPITECH PROJECT, 2020
** life.c
** File description:
** life.c
*/

#include "defender.h"

void check_life(game *def)
{
    char *score = my_nbr_to_str(def->life.count);

    sfText_setString(def->life.text, score);
}

void create_life(game *def)
{
    char *score = my_nbr_to_str(def->life.count);

    def->life.font = sfFont_createFromFile("assets/font.ttf");
    def->life.text = sfText_create();
    def->life.pos.x = 145;
    def->life.pos.y = 28;
    sfText_setString(def->life.text, score);
    sfText_setFont(def->life.text, def->life.font);
    sfText_setCharacterSize(def->life.text, 10);
    sfText_setPosition(def->life.text, def->life.pos);
}