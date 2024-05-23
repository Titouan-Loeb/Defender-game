/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** defense_type.c
*/

#include "defender.h"

void archer_defense(game *def, sfVector2i mouse, int i)
{
    if (def->tower[i].disp_cir == true && def->tower[i].rect.left == 0 &&
        mouse.x >= def->tower[i].pos.x + arc_but_off_left + def_width/2 &&
        mouse.x <= def->tower[i].pos.x + arc_but_off_right  + def_width/2 &&
        mouse.y >= def->tower[i].pos.y + arc_but_off_top + def_height/2 + 30 &&
        mouse.y <= def->tower[i].pos.y + arc_but_off_bot + def_height/2 + 30 &&
        def->money.count >= archer_cost) {
        def->tower[i].rect = (sfIntRect){300, 0, def_width, def_height};
        sfSprite_setTextureRect(def->tower[i].sprite, def->tower[i].rect);
        def->tower[i].damage = 5;
        def->tower[i].delay_attack = 0.8;
        def->tower[i].spe = archer;
        def->money.count -= archer_cost;
        def->tower[i].cost = 120;
        check_money(def);
        def->tower[i].range = 220;
        upgrade_circle(def, i);
    }
}

void mage_defense(game *def, sfVector2i mouse, int i)
{
    if (def->tower[i].disp_cir == true && def->tower[i].rect.left == 0 &&
        mouse.x > def->tower[i].pos.x + mage_but_off_left + def_width/2 &&
        mouse.x < def->tower[i].pos.x + mage_but_off_right + def_width/2 &&
        mouse.y > def->tower[i].pos.y + mage_but_off_top + def_height/2 + 30 &&
        mouse.y < def->tower[i].pos.y + mage_but_off_bot + def_height/2 + 30 &&
        def->money.count >= mage_cost) {
        def->tower[i].rect = (sfIntRect){300, 150, def_width, def_height};
        sfSprite_setTextureRect(def->tower[i].sprite, def->tower[i].rect);
        def->tower[i].damage = 8;
        def->tower[i].delay_attack = 1.4;
        def->tower[i].spe = mage;
        def->money.count -= mage_cost;
        def->tower[i].cost = 120;
        check_money(def);
        def->tower[i].range = 200;
        upgrade_circle(def, i);
    }
}

void mortar_defense(game *def, sfVector2i mouse, int i)
{
    if (def->tower[i].disp_cir == true && def->tower[i].rect.left == 0 &&
        mouse.x > def->tower[i].pos.x + mort_but_off_left + def_width/2 &&
        mouse.x < def->tower[i].pos.x + mort_but_off_right + def_width/2 &&
        mouse.y > def->tower[i].pos.y + mort_but_off_top + def_height/2 + 30 &&
        mouse.y < def->tower[i].pos.y + mort_but_off_bot + def_height/2 + 30 &&
        def->money.count >= mortar_cost) {
        def->tower[i].rect = (sfIntRect){300, 300, def_width, def_height};
        sfSprite_setTextureRect(def->tower[i].sprite, def->tower[i].rect);
        def->tower[i].damage = 15;
        def->tower[i].cost = 120;
        def->money.count -= mortar_cost;
        check_money(def);
        def->tower[i].spe = mortar;
        def->tower[i].delay_attack = 3.5;
        def->tower[i].range = 190;
        upgrade_circle(def, i);
    }
}

void rock_defense(game *def, sfVector2i mouse, int i)
{
    if (def->tower[i].disp_cir == true && def->tower[i].rect.left == 0 &&
        mouse.x > def->tower[i].pos.x + rock_but_off_left + def_width/2 &&
        mouse.x < def->tower[i].pos.x + rock_but_off_right + def_width/2 &&
        mouse.y > def->tower[i].pos.y + rock_but_off_top + def_height/2 + 30 &&
        mouse.y < def->tower[i].pos.y + rock_but_off_bot + def_height/2 + 30 &&
        def->money.count >= rock_cost) {
        def->tower[i].rect = (sfIntRect){300, 450, def_width, def_height};
        sfSprite_setTextureRect(def->tower[i].sprite, def->tower[i].rect);
        def->tower[i].damage = 6;
        def->tower[i].spe = rock;
        def->tower[i].cost = 120;
        def->money.count -= rock_cost;
        check_money(def);
        def->tower[i].delay_attack = 1.2;
        def->tower[i].range = 210;
        upgrade_circle(def, i);
    }
}

void choose_defense_type(game *def, sfVector2i mouse)
{
    for (int i = 0; i < 7; i++) {
        archer_defense(def, mouse, i);
        mage_defense(def, mouse, i);
        mortar_defense(def, mouse, i);
        rock_defense(def, mouse, i);
    }
}