/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:42:10 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/28 17:43:21 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include "../srcs/libft/libft.h"
# include "games/ft_game.h"
# include "ft_parsing.h"

# define KEY_UP 119
# define KEY_DOWN 115
# define KEY_LEFT 97
# define KEY_RIGHT 100
# define KEY_ESC 65307
# define N 20000
# define PLAYER 'P'
# define EXIT 'E'
# define GHOST 'G'
# define ITEMS 'C'
# define WALL '1'
# define FREE '0'
# define NBR_GHOST 4

void	gui_manager(t_game *game);
void	gui_printer(t_game *game, int x, int y, void *img_ptr);
void	redraw_map(t_game *game);
void	gui_controller(t_game *game);
void	aredraw_map(t_game *game);
void	exit_game(t_game *game, int mode);
int		get_random_number(int limits);
void	handle_key_up(t_game *game);
void	handle_key_down(t_game *game);
void	handle_key_left(t_game *game);
void	handle_key_right(t_game *game);
void	handle_key_esc(t_game *game);
void	handle_ghost_render(t_game *game, int i, int j);
void	handle_player_render(t_game *game, int i, int j);
int		is_win(t_status *status);
int		is_solve(t_game *game);
int		is_valide_line(char *line, size_t size, t_map *map);
#endif
