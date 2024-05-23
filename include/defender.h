/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef __MY_DEFENDER__
#define __MY_DEFENDER__

#include "const.h"
#include "struct.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>

//CREATE
sfRenderWindow *window(void);
void create_game(game *defender);
void create_defenses(game *defender);
void create_mouse(game *defender);
void create_description(game *defender);
void create_pause(game *defender);
void create_wave_button(game *defender);
void create_drake(game *defender);
void create_enemies(game *defender);
void create_fire(game *defender);
void create_menus(game *defender);
void create_quit(game *defender);
void create_credits_menu(game *defender);
void create_back_credits(game *defender);
void create_musics(game *defender);
void create_restart(game *defender);
void recreate_wave(game *defender);
void create_win_lose(game *defender);
void create_option(game *defender);
int count_words(char **points_pos);

//DEFENSE_TYPE
void choose_defense_type(game *defender, sfVector2i mouse);
void archer_defense(game *defender, sfVector2i mouse, int i);
void mage_defense(game *defender, sfVector2i mouse, int i);
void mortar_defense(game *defender, sfVector2i mouse, int i);
void rock_defense(game *defender, sfVector2i mouse, int i);
void sell_defense(game *defender, sfVector2i mouse);

//MENU
void mouse_on_defense(game *defender);
void mouse_on_start(game *defender, sfVector2i mouse);
void mouse_on_quit(game *defender, sfVector2i mouse);
void mouse_on_credits(game *defender, sfVector2i mouse);
void mouse_on_options(game *defender, sfVector2i mouse);
void game_cursor(game *defender);
void play_game(game *defender);
void mouse_on_button(game *defender, sfVector2i mouse);
void space_menu(game *defender);
void menus(game *defender);
void credits(game *defender);
void quit_clic(game *defender, sfVector2i mouse);

//MAIN
void usage(void);
int main(int argc, char **argv, char **env);

//DRAW
void draw_game(game *defender);
void draw_menus(game *defender);
void draw_credits(game *defender);
void options_clic(game *defender, sfVector2i mouse);
void credits_clic(game *defender, sfVector2i mouse);
void clic_pause(game *defender, sfVector2i mouse);
void clic_description(game *defender, sfVector2i mouse);
void clic_wave(game *defender, sfVector2i mouse);
void clic_fire(game*defender, sfVector2i mouse);
void clic_sound(game *defender);
void start_clic(game *defender, sfVector2i mouse);
void animated_drake(game *defender);
void animated_gobelin(game *defender);
void animated_fire(game *defender);
void draw_option(game *defender);

//CREATE_WAYS
void create_ways2(game *defender);
void create_ways(game *defender);

//CIRCLE
void upgrade_circle(game *defender, int i);
void reset_circle(game *defender);
void reupgrade_circle(game *def, int i);
void degrade_circle(towers tower);
int is_on_sell(game *def, sfVector2i mouse, int i);

//LIB
void my_putstr(char const *str);
void my_putchar(char c);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char **my_str_to_word_array(char *str);
char *my_nbr_to_str(int nbr);
char *my_strcat(char *str, char *s2);

//CLIC PAUSE
void clic_restart(game *defender, sfVector2i mouse);
void clic_quitter(game *defender, sfVector2i mouse);
void clic_music(game *defender, sfVector2i mouse);
void clic_on_pause(game *defender, sfVector2i mouse);

//MOVE
void move_enemy(game *defender, int i);
void move_enemies(game *defender);
void clic_drake(game *defender, sfVector2i mouse);
int square(sfIntRect *rect, int size, int max);
void fly_drake(game *defender);

//DESTROY
void destroy(game *defender);
void destroy_musics(game *defender);

//MUSIC
void setup_menu_music(game *defender);
void setup_game_music(game *defender);
void disable_musics(game *defender);
void disable_sounds(game *defender);
void unable_musics(game *defender);
void play_death_enemy(game *defender, enemies enemy);
void play_win_enemy(game *defender, enemies enemy);

//SETUP_START
void setup_var(game *defender);
void reset_enemies_pos(game *defender);
void reset_towers(game *defender);
void restart_game(game *defender);
void restart_game_wave(game *def);

//PAUSE
void mouse_restart(game *defender);
void mouse_sound(game *defender);
void mouse_quit_pause(game *defender);
void mouse_music(game *defender);
void mouse_close(game *defender);
void create_sound_off(game *defender);
void check_sound_off(game *defender);
void check_music_off(game *defender);
void setup_bool_pause_false(game *defender);

//MONEY
void check_money(game *defender);
void create_money(game *defender);

//LIFE
void create_life(game *defender);
void check_life(game *defender);

//HTP
void clic_htp(game *defender, sfVector2i mouse);
void create_htp(game *defender);
void mouse_htp(game *defender);
void create_close_htp(game *defender);
void clic_close_htp(game *defender, sfVector2i mouse);

//LOSE
void clic_lose_restart(game *defender, sfVector2i mouse);
void clic_lose_quit(game *def, sfVector2i mouse);

//WIN
void clic_win_quit(game *def, sfVector2i mouse);
void clic_win_restart(game *def, sfVector2i mouse);

//ATTACK
void defense_attack(game *defender);
void move_attack(game *defender, towers *tower);
void get_move_delta_t(game *defender);
void end_attack(game *defender, towers *tower);
void attack_in_zone(game *def, int zone);
void enemy_dead(game *def, int i);

//OPTION
void on_clic_option(game *defender);
void event_option(game *defender);
void option(game *defender);
void clic_quit_option(game *defender, sfVector2i mouse);
void clic_plus_enemy(game *defender, sfVector2i mouse);
void clic_less_enemy(game *defender, sfVector2i mouse);
void clic_less_purcent(game *defender, sfVector2i mouse);
void clic_plus_purcent(game *defender, sfVector2i mouse);
void clic_music_option(game *def, sfVector2i mouse);
void clic_sound_option(game *def, sfVector2i mouse);

//WAVE
void create_nb_wave(game *defender);
void check_nb_wave(game *defender);
void create_wave_increase(game *defender);
void check_wave_increase(game *defender);
void create_wave_txt(game *def);
void check_wave_txt(game *def);
void create_wave_tot_txt(game *def);
void check_wave_tot_txt(game *def);

//WIN_LOSE
void is_lose(game *defender);

//CREATE_MOB
void mob_position(game *def, int square, int i);
void create_goblin(game *def, int i);
void create_wolf(game *def, int i);
void create_bandit(game *def, int i);
void create_golem(game *def, int i);

//ATTACK
void target_enemy(game *def, towers *tower);
void attack_bomb(game *def, towers *tower, int zone);
void attack_in_zone(game *def, int zone);
void get_move_delta_t(game *def);

//RANGE
int is_in_range(game *def, enemies *enemy, int zone);
int is_enemy_in_range(game *def, enemies *enemy, towers *tower);
int is_in_bomb(game *def, enemies *enemy_target, enemies *enemy, int zone);

//TOWER_ATTACK
void launch_attack(game *def, enemies *enemy, towers *tower);
void defense_attack(game *def);
void attack_enemy(game *def, int target, towers *tower);
void end_attack(game *def, towers *tower);

//GAME_SCREEN
void upgrade_defense(game *def, sfVector2i mouse);
void clic_circle(game *def, sfVector2i mouse);
void do_pause_or_play(game *def);
void play_game(game *def);

//CHECK_WITH_MOUSE
int is_mouse_on_tower(game *def, sfVector2i mouse, int i);
void mouse_on_defense(game *def);
void spell_follow_mouse(game *def, sfVector2i mouse);

//EVENT_GAME_SCREEN
void event_game(game *def);

#endif /*__MY_DEFENDER__*/
