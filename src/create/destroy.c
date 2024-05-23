/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** destroy.c
*/

#include "defender.h"

void destroy_enemies(game *def)
{
    for (int i = 0; i < def->nb_enemy.count; i++) {
        sfClock_destroy(def->enemy[i].clock.clock);
        sfSprite_destroy(def->enemy[i].sprite);
        sfTexture_destroy(def->enemy[i].texture);
    }
    free(def->enemy);
}

void destroy_towers(game *def)
{
    for (int i = 0; i < 7; i++) {
        sfSprite_destroy(def->tower[i].sprite);
        sfTexture_destroy(def->tower[i].texture);
        sfSprite_destroy(def->tower[i].circle.sprite);
        sfTexture_destroy(def->tower[i].circle.texture);
        if (def->tower[i].attacking == true) {
            sfSprite_destroy(def->tower[i].attack.sprite);
            sfTexture_destroy(def->tower[i].attack.texture);
            sfClock_destroy(def->tower[i].attack.clock.clock);
        }
    }
    free(def->tower);
}

void destroy_text(game *def)
{
    sfText_destroy(def->money.text);
    sfFont_destroy(def->money.font);
    sfText_destroy(def->nb_enemy.text);
    sfFont_destroy(def->nb_enemy.font);
    sfText_destroy(def->nb_wave.text);
    sfFont_destroy(def->nb_wave.font);
    sfText_destroy(def->life.text);
    sfFont_destroy(def->life.font);
    sfText_destroy(def->wave_increase.text);
    sfFont_destroy(def->wave_increase.font);
}

void destroy_musics(game *def)
{
    for (int i = 0; i < 11; i++)
        sfMusic_destroy(def->music[i]);
}

void destroy(game *def)
{
    sfRenderWindow_destroy(def->wind);
    destroy_musics(def);
    destroy_enemies(def);
    destroy_towers(def);
}