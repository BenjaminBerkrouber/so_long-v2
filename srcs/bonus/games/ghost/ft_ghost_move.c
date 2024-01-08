/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ghost_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:55:36 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/22 12:57:21 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	update_ghost_position(t_ghost *ghost, int new_x, int new_y)
{
	ghost->last_pos->x = ghost->x;
	ghost->last_pos->y = ghost->y;
	ghost->x = new_x;
	ghost->y = new_y;
}

void	update_map_and_ghost(t_game *game, t_ghost *ghost, int new_x, int new_y)
{
	game->map->map[ghost->x][ghost->y] = ghost->last_case;
	ghost->last_case = game->map->map[new_x][new_y];
	game->map->map[new_x][new_y] = GHOST;
	update_ghost_position(ghost, new_x, new_y);
}

void	execute_move(t_game *game, t_ghost *ghost, int new_x, int new_y)
{
	if (game->map->map[new_x][new_y] == PLAYER)
	{
		exit_game(game, 1);
		return ;
	}
	update_map_and_ghost(game, ghost, new_x, new_y);
}

void	update_single_ghost(t_game *game, t_ghost *ghost)
{
	int	new_x;
	int	new_y;

	get_next_position(game, ghost, &new_x, &new_y);
	if (can_move_to(game, new_x, new_y))
		execute_move(game, ghost, new_x, new_y);
}

void	update_pos_ghost(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->ghosts->nbr_ghosts)
	{
		update_single_ghost(game, game->ghosts->ghost[i]);
		i++;
	}
}
