NAME = so_long
CC = clang
CFLAGS = -g -Wall -Wextra -Werror -I.
SRC_DIR = srcs/
SRC = 	srcs/main.c \
		srcs/parcing/ft_parcing.c \
		srcs/parcing/ft_solvable.c \
		srcs/parcing/ft_parcing_utils.c \
		srcs/parcing/ft_parcing_utils2.c \
		srcs/exit/ft_exit_game.c \
		srcs/exit/ft_exit_item.c \
		srcs/exit/ft_exit_status.c \
		srcs/exit/ft_exit_map.c \
		srcs/exit/ft_exit_ressources.c\
		srcs/games/game.c \
		srcs/games/status.c \
		srcs/games/exit/ft_exit.c \
		srcs/games/player/ft_player.c \
		srcs/games/items/ft_item.c \
		srcs/games/maps/map.c \
		srcs/gui/gui_controller.c \
		srcs/gui/gui_init_ptr.c \
		srcs/gui/gui_draw.c \
		srcs/gui/gui_key.c \
		srcs/gui/player/gui_player.c 
OBJ = $(SRC:.c=.o)
SRC_BONUS = srcs/main.c \
		srcs/parcing/ft_parcing.c \
		srcs/parcing/ft_solvable.c \
		srcs/parcing/ft_parcing_utils.c \
		srcs/parcing/ft_parcing_utils2.c \
		srcs/bonus/exit/ft_exit_game_bonus.c \
		srcs/exit/ft_exit_item.c \
		srcs/exit/ft_exit_map.c \
		srcs/exit/ft_exit_status.c \
		srcs/bonus/exit/ft_exit_ghosts_bonus.c \
		srcs/bonus/exit/ft_exit_ressources_bonus.c\
		srcs/bonus/games/game_bonus.c \
		srcs/bonus/games/status_bonus.c \
		srcs/bonus/games/ghost/ft_ghost.c \
		srcs/bonus/games/ghost/ft_ghost_move.c \
		srcs/bonus/games/ghost/ft_ghost_move_utils.c \
		srcs/games/exit/ft_exit.c \
		srcs/games/player/ft_player.c \
		srcs/games/items/ft_item.c \
		srcs/games/maps/map.c \
		srcs/bonus/gui/gui_controller_bonus.c \
		srcs/bonus/gui/gui_init_ptr_bonus.c \
		srcs/bonus/gui/gui_draw_bonus.c \
		srcs/gui/gui_key.c \
		srcs/bonus/gui/player/gui_player_bonus.c 
OBJ_BONUS = $(SRC_BONUS:.c=.o)

LIBFT_DIR = srcs/libft
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX_DIR = minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx_Linux.a

INCLUDES = -I includes/ -I $(LIBFT_DIR)/includes/ -I $(MINILIBX_DIR)
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz

all: $(NAME)

bonus : $(LIBFT) $(MINILIBX) $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) $(LIBFT) $(MINILIBX) -o $(NAME) $(CFLAGS) $(INCLUDES) $(LDFLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MINILIBX):
	make -C $(MINILIBX_DIR)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(MINILIBX) -o $(NAME) $(CFLAGS) $(INCLUDES) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)
	make -C $(LIBFT_DIR) clean
	make -C $(MINILIBX_DIR) clean

fclean: clean
	rm -rf $(NAME) a.out
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
