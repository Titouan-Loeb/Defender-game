/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** create_defenses.c
*/

#include "defender.h"

void create_defense(game *def, int i)
{
    def->tower[i].circle.sprite = sfSprite_create();
    def->tower[i].circle.texture =
    sfTexture_createFromFile("assets/new_first_circle.png", NULL);
    sfSprite_setTexture(def->tower[i].circle.sprite,
    def->tower[i].circle.texture, sfTrue);
    sfSprite_setPosition(def->tower[i].circle.sprite, def->tower[i].circle.pos);
    def->tower[i].sprite = sfSprite_create();
    def->tower[i].texture =
    sfTexture_createFromFile("assets/3towers_3levelb_.png", NULL);
    sfSprite_setTexture(def->tower[i].sprite, def->tower[i].texture, sfTrue);
    sfSprite_setPosition(def->tower[i].sprite, def->tower[i].pos);
    def->tower[i].rect = (sfIntRect){0, 0, 150, 150};
    sfSprite_setTextureRect(def->tower[i].sprite, def->tower[i].rect);
    def->tower[i].disp_cir = false;
    def->tower[i].attacking = false;
    def->tower[i].spe = null;
}

void fill_tower_pos(int a, int i, char **points_pos, game *def)
{
    if (points_pos[a] != NULL && points_pos[a + 1] != NULL) {
        def->tower[i].pos =
        (sfVector2f){my_getnbr(points_pos[a]) - def_width/2,
        my_getnbr(points_pos[a + 1]) - def_height/2 - 30};
        def->tower[i].circle.pos =
        (sfVector2f){my_getnbr(points_pos[a]) - circ_width/2,
        my_getnbr(points_pos[a + 1]) - circ_height/2 - 30};
    }
}

void fill_tower(char **points_pos, game *def)
{
    int a = 0;

    for (int i = 0; i < 7 ; i++) {
        if (def->err != 84)
            fill_tower_pos(a, i, points_pos, def);
        create_defense(def, i);
        a += 2;
    }
}

void create_defenses(game *def)
{
    char map_file[131];
    int fd = open("tower_pos", O_RDONLY);
    char **points_pos = NULL;

    def->tower = malloc(sizeof(towers) * 7);
    for (int i = 0; i < 7; i++)
        def->tower[i].pos = (sfVector2f){0, 0};
    if (fd != -1) {
        read(fd, &map_file, 130);
        map_file[130] = '\0';
        points_pos = my_str_to_word_array(map_file);
        if (count_words(points_pos) != 14)
            def->err = 84;
        fill_tower(points_pos, def);
    }
}