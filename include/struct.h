/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

typedef enum tower_specialty
{
    null = -1,
    archer = 0,
    mage = 1,
    mortar = 2,
    rock = 3
}tower_spe;

typedef struct clock_parameters
{
    sfClock *clock;
    sfTime time;
    float sec;
}clocks;

typedef enum ennemy_type
{
    gobelin = 0,
    wolf = 1,
    bandit = 2,
    golem = 3
}ennemy_type;

typedef struct ennemy_parameters
{
    ennemy_type type;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    clocks clock;
    int speed;
    int life;
    int damage;
    int loc;
    int max_square;
}enemies;

typedef struct back_parameters
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f speed;
    sfIntRect rect;
    clocks clock;
    int activated;
    int disp_panel;
}back;

typedef struct mouse_parameters
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
}image;

typedef struct tower_parameters
{
    sfSprite *sprite;
    sfTexture *texture;
    image circle;
    sfVector2f pos;
    sfIntRect rect;
    tower_spe spe;
    back attack;
    int range;
    float delay_attack;
    int target;
    int cost;
    int attacking;
    int level;
    int damage;
    int disp_cir;
}towers;

typedef struct mob_parameters
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2i *pos;
    sfIntRect rect;
    clocks clock;

    sfSprite *sprite_des;
    sfTexture *texture_des;
    sfVector2f pos_des;

    sfSprite *panel_sprite;
    sfTexture *panel_texture;
    sfVector2f panel_pos;
    int disp_panel;
}mob;

typedef struct map_parameters
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f *way;
    sfIntRect rect;
}maps;

typedef struct menu_parameters
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    sfSprite *off_sp;
    sfTexture *off_text;
    int disp_panel;
    int disp_off;
}menu;

typedef struct score_parameters
{
    int count;
    sfText *text;
    sfFont *font;
    sfVector2f pos;
}score;

typedef struct defender_game
{
    clocks move;
    menu back_credits;
    menu restart;
    menu music_an;
    menu sound_an;
    menu close_htp;
    menu close_an;
    menu quit_pause;
    menu credits;
    menu options;
    menu quit;
    menu htp;
    menu start;
    back drake;
    back fly_drake;
    back fire;
    menu game_menu;
    menu credits_menu;
    menu wave_button;
    menu pause;
    menu lose;
    menu win;
    menu option;
    maps map;
    mob gobelin;
    towers *tower;
    enemies *enemy;
    score nb_enemy;
    score nb_wave;
    score wave_txt;
    score wave_tot;
    sfRenderWindow *wind;
    sfEvent event;
    image cursor;
    sfMusic **music;
    score wave_increase;
    int music_on;
    int sound_on;
    int stop;
    int wave_num;
    int clear;
    int err;
    score money;
    score life;
}game;

#endif /* !STRUCT_H_ */