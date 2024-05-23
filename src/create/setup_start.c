/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** setup_start.c
*/

#include "defender.h"

void setup_var(game *def)
{
    def->music_on = 1;
    def->sound_on = 1;
    def->stop = 0;
    def->nb_enemy.count = 10;
    def->nb_wave.count = 1;
    def->wave_num = 0;
    def->stop = 0;
    def->clear = 0;
    def->wave_increase.count = 20;
    def->life.count = 20;
    def->money.count = 300;
}

void reset_enemies_pos(game *def)
{
    int square = 0;

    for (int i = 0; i < def->nb_enemy.count; i++) {
        square = rand() % 14;
        if (i == 0) {
            def->enemy[i].pos.x = def->map.way[0].x + square * 30;
            def->enemy[i].pos.y = def->map.way[0].y;
        } else {
            def->enemy[i].pos.x = def->enemy[i - 1].pos.x + 5 * square + 5;
            def->enemy[i].pos.y = def->map.way[0].y;
        }
        sfSprite_setPosition(def->enemy[i].sprite, def->enemy[i].pos);
        def->enemy[i].loc = 0;
    }
}

void reset_towers(game *def)
{
    for (int i = 0; i < 7; i++) {
        def->tower[i].rect = (sfIntRect){0, 0, 150, 150};
        sfSprite_setTextureRect(def->tower[i].sprite, def->tower[i].rect);
        def->tower[i].attack.disp_panel = false;
        def->tower[i].attacking = false;
    }
}

void restart_game(game *def)
{
    reset_enemies_pos(def);
    reset_towers(def);
    reset_circle(def);
    setup_game_music(def);
    restart_game_wave(def);
    def->money.count = 300;
    check_money(def);
    def->life.count = 20;
    check_life(def);
    def->wave_button.disp_panel = false;
    def->drake.disp_panel = true;
    def->fly_drake.disp_panel = false;
    def->drake.pos = (sfVector2f){136, 392};
    sfSprite_setPosition(def->drake.sprite, def->drake.pos);
    def->fly_drake.pos = (sfVector2f){-205, 230};
    sfSprite_setPosition(def->fly_drake.sprite, def->fly_drake.pos);
    def->fly_drake.rect = (sfIntRect){0, 0, 500, 500};
    sfSprite_setTextureRect(def->fly_drake.sprite, def->fly_drake.rect);
}

void setup_bool_pause_false(game *def)
{
    def->pause.disp_panel = false;
    def->sound_an.disp_panel = false;
    def->music_an.disp_panel = false;
    def->restart.disp_panel = false;
    def->quit_pause.disp_panel = false;
    def->close_an.disp_panel = false;
    def->music_an.disp_off = false;
    def->sound_an.disp_off = false;
    def->stop = false;
    def->lose.disp_panel = false;
    def->win.disp_panel = false;
}