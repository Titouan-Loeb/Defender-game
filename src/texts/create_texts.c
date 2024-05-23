/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** create_texts.c
*/

#include "defender.h"

void create_nb_wave(game *def)
{
    char *score = my_nbr_to_str(def->nb_wave.count);

    def->nb_wave.font = sfFont_createFromFile("assets/font.ttf");
    def->nb_wave.text = sfText_create();
    def->nb_wave.pos.x = 680;
    def->nb_wave.pos.y = 675;
    sfText_setString(def->nb_wave.text, score);
    sfText_setFont(def->nb_wave.text, def->nb_wave.font);
    sfText_setCharacterSize(def->nb_wave.text, 20);
    sfText_setPosition(def->nb_wave.text, def->nb_wave.pos);
}

void create_wave_increase(game *def)
{
    char *score = my_nbr_to_str(def->wave_increase.count);

    def->wave_increase.font = sfFont_createFromFile("assets/font.ttf");
    def->wave_increase.text = sfText_create();
    def->wave_increase.pos.x = 1205;
    def->wave_increase.pos.y = 675;
    sfText_setString(def->wave_increase.text, score);
    sfText_setFont(def->wave_increase.text, def->wave_increase.font);
    sfText_setCharacterSize(def->wave_increase.text, 20);
    sfText_setPosition(def->wave_increase.text, def->wave_increase.pos);
}