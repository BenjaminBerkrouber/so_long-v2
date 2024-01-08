/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:44:20 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/28 17:45:32 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GAME_H
# define FT_GAME_H

# include "ft_map.h"
# include "ft_status.h"
# include "ft_ghost.h"
# include "ft_ressources.h"

typedef struct s_game
{
	t_status		*status;
	t_map			*map;
	t_ressources	*ressources;
	int				move_cpt;
	int				frame_count;
	t_ghosts		*ghosts;
	int				score;
}	t_game;

t_game	*init_game(char *str);
void	move_player(t_game *game, int dx, int dy);
void	aredraw_map(t_game *game);
t_ghost	*set_ghost(t_map *map);
void	update_pos_ghost(t_game *game);
void	get_next_position(t_game *game, t_ghost *ghost, int *new_x, int *new_y);
int		can_move_to(t_game *game, int x, int y);
void	init_ressources(t_game *game);
int		close_window(t_game *game);
#endif
