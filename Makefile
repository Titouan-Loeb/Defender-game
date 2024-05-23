##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/clic/clic.c									\
		src/clic/clic_lose.c							\
		src/clic/clic_menu.c							\
		src/clic/clic_option_music.c					\
		src/clic/clic_option.c							\
		src/clic/clic_pause.c							\
		src/clic/clic_win.c								\
		src/create/create2.c							\
		src/create/create3.c							\
		src/create/create.c								\
		src/create/create_defenses.c					\
		src/create/create_menu.c						\
		src/create/create_mob.c							\
		src/create/create_pause.c						\
		src/create/create_ways.c						\
		src/create/destroy.c							\
		src/create/setup_start.c						\
		src/game_play/attack/attack.c					\
		src/game_play/attack/attack_movement.c			\
		src/game_play/attack/ranges.c					\
		src/game_play/attack/tower_attack.c				\
		src/game_play/move.c							\
		src/game_play/wave.c							\
		src/game_play/win_lose.c						\
		src/lib/my_getnbr.c								\
		src/lib/my_nbr_to_str.c							\
		src/lib/my_putstr.c								\
		src/lib/my_strcat.c								\
		src/lib/my_str_to_word_array.c					\
		src/music/check_off.c							\
		src/music/mob_sounds.c							\
		src/music/switch_music.c						\
		src/objects/circle.c							\
		src/objects/cursor.c							\
		src/objects/cursor_game.c						\
		src/objects/defense_type.c						\
		src/objects/fly_drake.c							\
		src/objects/htp.c								\
		src/objects/life.c								\
		src/objects/money.c								\
		src/screens/credits.c							\
		src/screens/game_screen/check_with_mouse_pos.c	\
		src/screens/game_screen/event_game_screen.c		\
		src/screens/game_screen/game_screen.c			\
		src/screens/game_screen/mouse_button_pause.c	\
		src/screens/menus.c								\
		src/screens/option.c							\
		src/screens/pause.c								\
		src/texts/create_texts.c						\
		src/texts/refresh_texts.c						\
		src/texts/wave_txt.c							\
		src/visual/animated.c							\
		src/visual/draw.c								\
		src/visual/draw_screens.c						\
		src/main.c

OBJ     =       $(SRC:.c=.o)

NAME    =       my_defender

CFLAGS 		=   -Wextra -Wall

LCSFML		=	-lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -lm

CPPFLAGS	+=	-I ./include

all:    $(NAME)

$(NAME):        $(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(LCSFML)

clean:
			rm -rf $(OBJ)
			rm -rf *~

fclean: clean
			rm -rf $(NAME)

re:		fclean all

.PHONY:	clean fclean all re
