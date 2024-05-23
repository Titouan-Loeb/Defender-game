/*
** EPITECH PROJECT, 2020
** MUL_defender_2019
** File description:
** const.h
*/

#ifndef CONST_H_
#define CONST_H_

#include <math.h>

#define RTD(x) (x * 180 / M_PI)
#define DTR(x) (x * M_PI / 180)
#define ABS(a) ((a >= 0) ? (a) : -(a))

//musics
static const int menu_m = 0;
static const int game_m = 1;
static const int clic_m = 2;
static const int goblin_m = 3;
static const int goblin2_m = 4;
static const int wolf_m = 5;
static const int wolf2_m = 6;
static const int bandit_m = 7;
static const int bandit2_m = 8;
static const int golem_m = 9;
static const int golem2_m = 10;

//cost_defense
static const int archer_cost = 95;
static const int mage_cost = 119;
static const int mortar_cost = 153;
static const int rock_cost = 187;
static const int upgrade_cost = 120;

//fly_drake
static const int fly_darke_left = 144;
static const int fly_darke_right = 254;
static const int fly_darke_top = 400;
static const int fly_darke_bot = 492;

//restart but
static const int restart_left = 566;
static const int restart_right = 940;
static const int restart_top = 471;
static const int restart_bot = 594;

//quit_but
static const int quit_left = 986;
static const int quit_right = 1360;
static const int quit_top = 473;
static const int quit_bot = 589;

//music_but
static const int music_left = 676;
static const int music_right = 887;
static const int music_top = 205;
static const int music_bot = 391;

//music_sound
static const int sound_left = 1048;
static const int sound_right = 1257;
static const int sound_top = 207;
static const int sound_bot = 392;

//fire_but
static const int fire_left = 244;
static const int fire_right = 306;
static const int fire_top = 1000;
static const int fire_bot = 1060;

//defense
static const int def_width = 150;
static const int def_height = 150;

//circle
static const int circ_width = 1000;
static const int circ_height = 563;

//sell_button
static const int sell_but_off_left = -27;
static const int sell_but_off_right = 18;
static const int sell_but_off_top = 25;
static const int sell_but_off_bot = 67;

//archer_but
static const int arc_but_off_left = -97;
static const int arc_but_off_right = -38;
static const int arc_but_off_top = -130;
static const int arc_but_off_bot = -70;

//mage_but
static const int mage_but_off_left = 32;
static const int mage_but_off_right = 88;
static const int mage_but_off_top = -130;
static const int mage_but_off_bot = -70;

//mortar_but
static const int mort_but_off_left = -97;
static const int mort_but_off_right = -38;
static const int mort_but_off_top = 15;
static const int mort_but_off_bot = 75;

//rock_defense
static const int rock_but_off_left = 32;
static const int rock_but_off_right = 88;
static const int rock_but_off_top = 15;
static const int rock_but_off_bot = 75;

//upgrade_button
static const int up_left = -31;
static const int up_right = 24;
static const int up_top = -162;
static const int up_bot = -114;

//descrition_button
static const int desc_left = 1740;
static const int desc_right = 1790;
static const int desc_top = 1015;
static const int desc_bot = 1065;

//pause_button
static const int pause_left = 1788;
static const int pause_right = 1833;
static const int pause_top = 16;
static const int pause_bot = 52;

//pause_panel
static const int pause_panel_left = 418;
static const int pause_panel_right = 1497;
static const int pause_panel_top = 97;
static const int pause_panel_bot = 661;

//wave_button
static const int wave_left = 1820;
static const int wave_right = 1875;
static const int wave_top = 270;
static const int wave_bot = 325;

//start_button
static const int start_left = 316;
static const int start_right = 625;
static const int start_top = 627;
static const int start_bot = 771;

//menu_quit_button
static const int quit_menu_left = 379;
static const int quit_menu_right = 541;
static const int quit_menu_top = 914;
static const int quit_menu_bot = 993;

//credits_back_button
static const int quit_cred_left = 458;
static const int quit_cred_right = 616;
static const int quit_cred_top = 760;
static const int quit_cred_bot = 852;

//option_button
static const int option_left = 354;
static const int option_rigth = 578;
static const int option_top = 773;
static const int option_bot = 843;

//credit_button
static const int credits_left = 407;
static const int credits_right = 564;
static const int credits_top = 845;
static const int credits_bot = 912;

//plus_enemy_button
static const int plus_enemy_left = 777;
static const int plus_enemy_rigth = 858;
static const int plus_enemy_top = 640;
static const int plus_enemy_bot = 730;

//less_enemy_button
static const int less_enemy_left = 555;
static const int less_enemy_rigth = 645;
static const int less_enemy_top = 638;
static const int less_enemy_bot = 730;

//plus_purcent_button
static const int plus_purcent_left = 1294;
static const int plus_purcent_rigth = 1380;
static const int plus_purcent_top = 638;
static const int plus_purcent_bot = 730;

//less_purcent_button
static const int less_purcent_left = 1080;
static const int less_purcent_rigth = 1168;
static const int less_purcent_top = 638;
static const int less_purcent_bot = 730;

//option_quit_button
static const int quit_option_left = 761;
static const int quit_option_rigth = 1166;
static const int quit_option_top = 769;
static const int quit_option_bot = 901;

#endif /* !CONST_H_ */
