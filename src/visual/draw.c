/*
** EPITECH PROJECT, 2020
** game.c
** File description:
** game.c
*/

#include "defender.h"

void draw_pause(game *def)
{
    if (def->pause.disp_panel == true)
        sfRenderWindow_drawSprite(def->wind, def->pause.sprite, NULL);
    if (def->restart.disp_panel == true)
        sfRenderWindow_drawSprite(def->wind, def->restart.sprite, NULL);
    if (def->quit_pause.disp_panel == true)
        sfRenderWindow_drawSprite(def->wind, def->quit_pause.sprite, NULL);
    if (def->sound_an.disp_panel == true)
        sfRenderWindow_drawSprite(def->wind, def->sound_an.sprite, NULL);
    if (def->music_an.disp_off == true)
        sfRenderWindow_drawSprite(def->wind, def->music_an.off_sp, NULL);
    if (def->music_an.disp_panel == true)
        sfRenderWindow_drawSprite(def->wind, def->music_an.sprite, NULL);
    if (def->sound_an.disp_off == true)
        sfRenderWindow_drawSprite(def->wind, def->sound_an.off_sp, NULL);
    if (def->htp.disp_panel == true)
        sfRenderWindow_drawSprite(def->wind, def->htp.sprite, NULL);
    if (def->close_an.disp_panel == true)
        sfRenderWindow_drawSprite(def->wind, def->close_an.sprite, NULL);
    if (def->close_htp.disp_panel == true)
        sfRenderWindow_drawSprite(def->wind, def->close_htp.sprite, NULL);
}

void draw_defense_and_enemy(game *def)
{
    for (int i = 0; i < def->nb_enemy.count; i++)
        if (def->enemy[i].life > 0)
            sfRenderWindow_drawSprite(def->wind, def->enemy[i].sprite, NULL);
    for (int i = 0; i < 7; i++)
        sfRenderWindow_drawSprite(def->wind, def->tower[i].sprite, NULL);
    for (int i = 0; i < 7; i++)
        if (def->tower[i].disp_cir)
            sfRenderWindow_drawSprite(def->wind,
            def->tower[i].circle.sprite, NULL);
    for (int i = 0; i < 7 ; i++)
        if (def->tower[i].attack.disp_panel == true)
            sfRenderWindow_drawSprite(def->wind,
            def->tower[i].attack.sprite, NULL);
}

void draw_drake(game *def)
{
    if (def->drake.disp_panel == true)
        sfRenderWindow_drawSprite(def->wind, def->drake.sprite, NULL);
    if (def->fly_drake.disp_panel == true)
        sfRenderWindow_drawSprite(def->wind, def->fly_drake.sprite, NULL);
}

void draw_texts(game *def)
{
    sfRenderWindow_drawText(def->wind, def->money.text, NULL);
    sfRenderWindow_drawText(def->wind, def->life.text, NULL);
    sfRenderWindow_drawText(def->wind, def->wave_txt.text, NULL);
    sfRenderWindow_drawText(def->wind, def->wave_tot.text, NULL);
}

void draw_game(game *def)
{
    sfRenderWindow_drawSprite(def->wind, def->map.sprite, NULL);
    sfRenderWindow_drawSprite(def->wind, def->cursor.sprite, NULL);
    draw_defense_and_enemy(def);
    sfRenderWindow_drawSprite(def->wind, def->gobelin.sprite_des, NULL);
    if (def->wave_button.disp_panel == false)
        sfRenderWindow_drawSprite(def->wind, def->wave_button.sprite, NULL);
    draw_drake(def);
    draw_texts(def);
    if (def->fire.disp_panel == true)
        sfRenderWindow_drawSprite(def->wind, def->fire.sprite, NULL);
    if (def->gobelin.disp_panel == true)
        sfRenderWindow_drawSprite(def->wind, def->gobelin.panel_sprite, NULL);
    if (def->lose.disp_panel == true)
        sfRenderWindow_drawSprite(def->wind, def->lose.sprite, NULL);
    if (def->win.disp_panel == true)
        sfRenderWindow_drawSprite(def->wind, def->win.sprite, NULL);
    draw_pause(def);
    sfRenderWindow_drawSprite(def->wind, def->cursor.sprite, NULL);
    sfRenderWindow_display(def->wind);
}