/*
** EPITECH PROJECT, 2020
** wave_txt.c
** File description:
** wave_txt.c
*/

#include "defender.h"

void check_wave_txt(game *def)
{
    char *score = my_nbr_to_str(def->wave_num);

    sfText_setString(def->wave_txt.text, score);
}

void create_wave_txt(game *def)
{
    char *score = my_nbr_to_str(def->wave_num);

    def->wave_txt.text = sfText_create();
    def->wave_txt.font = sfFont_createFromFile("assets/font.ttf");
    def->wave_txt.pos.x = 350;
    def->wave_txt.pos.y = 28;
    sfText_setString(def->wave_txt.text, score);
    sfText_setFont(def->wave_txt.text, def->wave_txt.font);
    sfText_setCharacterSize(def->wave_txt.text, 10);
    sfText_setPosition(def->wave_txt.text, def->wave_txt.pos);
}

void check_wave_tot_txt(game *def)
{
    char *score = my_nbr_to_str(def->nb_wave.count);
    char *on = "/   ";
    char *string = NULL;

    string = my_strcat(on, score);
    sfText_setString(def->wave_tot.text, string);
}

void create_wave_tot_txt(game *def)
{
    char *score = my_nbr_to_str(def->nb_wave.count);
    char *on = "/   ";
    char *string = NULL;

    string = my_strcat(on, score);
    def->wave_tot.text = sfText_create();
    def->wave_tot.font = sfFont_createFromFile("assets/font.ttf");
    def->wave_tot.pos.x = 380;
    def->wave_tot.pos.y = 28;
    sfText_setString(def->wave_tot.text, string);
    sfText_setFont(def->wave_tot.text, def->wave_tot.font);
    sfText_setCharacterSize(def->wave_tot.text, 10);
    sfText_setPosition(def->wave_tot.text, def->wave_tot.pos);
}