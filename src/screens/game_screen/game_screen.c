/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** game_screen.c
*/

#include "defender.h"

void upgrade_defense(game *def, sfVector2i mouse)
{
    for (int i = 0; i < 7; i++)
        if (def->tower[i].disp_cir == true &&
        def->tower[i].rect.left > 150 &&
        mouse.x > def->tower[i].pos.x + up_left + def_width/2 &&
        mouse.x < def->tower[i].pos.x + up_right + def_width/2 &&
        mouse.y > def->tower[i].pos.y + up_top + def_height/2 + 30 &&
        mouse.y < def->tower[i].pos.y + up_bot + def_height/2 + 30 &&
        def->tower[i].rect.left < 1800 && def->money.count >= 100 &&
        def->money.count >= def->tower[i].cost) {
            def->tower[i].rect.left += 300;
            def->money.count -= def->tower[i].cost;
            if (def->tower[i].rect.left >= 900) {
                def->tower[i].cost = 150;
                reupgrade_circle(def, i);
            }
            def->tower[i].damage += 2;
            check_money(def);
            sfSprite_setTextureRect(def->tower[i].sprite,
            def->tower[i].rect);
        }
}

void sell_defense(game *def, sfVector2i mouse)
{
    const int tower_cost[] = {archer_cost, mage_cost, mortar_cost, rock_cost};

    for (int i = 0; i < 7; i++) {
        if (is_on_sell(def, mouse, i) == 1 && def->tower[i].spe != null &&
            def->tower[i].disp_cir == true) {
            def->tower[i].rect.left = 0;
            def->tower[i].disp_cir = false;
            def->tower[i].damage = 0;
            check_money(def);
            degrade_circle(def->tower[i]);
            def->tower[i].delay_attack = 0;
            def->tower[i].range = 0;
            def->money.count += tower_cost[def->tower[i].spe] * 65 / 100;
            sfSprite_setTextureRect(def->tower[i].sprite, def->tower[i].rect);
            def->tower[i].spe = null;
        }
    }
}

void clic_circle(game *def, sfVector2i mouse)
{
    for (int i = 0; i < 7; i++) {
        if (is_mouse_on_tower(def, mouse, i) == 1 &&
            (i != 0 || def->tower[2].disp_cir == false))
            def->tower[i].disp_cir = true;
        else if (is_mouse_on_tower(def, mouse, i) == 0)
            def->tower[i].disp_cir = false;
    }
}

void do_pause_or_play(game *def)
{
    if (!def->stop && !def->pause.disp_panel &&
    !def->gobelin.disp_panel && !def->htp.disp_panel) {
        if (def->wave_button.disp_panel == true)
            move_enemies(def);
        mouse_on_defense(def);
        animated_drake(def);
        animated_gobelin(def);
        animated_fire(def);
        defense_attack(def);
        fly_drake(def);
        recreate_wave(def);
    } else {
        mouse_restart(def);
        mouse_quit_pause(def);
        mouse_music(def);
        mouse_sound(def);
        mouse_close(def);
        check_sound_off(def);
        check_music_off(def);
    }
}

void play_game(game *def)
{
    sfVector2i mouse;

    setup_game_music(def);
    while (sfRenderWindow_isOpen(def->wind)) {
        sfRenderWindow_setFramerateLimit(def->wind, 60);
        event_game(def);
        get_move_delta_t(def);
        do_pause_or_play(def);
        spell_follow_mouse(def, mouse);
        sfMusic_setLoop(def->music[1], sfTrue);
        check_money(def);
        draw_game(def);
        game_cursor(def);
        mouse_htp(def);
        is_lose(def);
    }
}