/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ghost_move_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:56:17 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/23 02:55:39 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	can_move_to(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map->x || y < 0 || y >= game->map->y)
		return (0);
	if (game->map->map[x][y] == WALL || game->map->map[x][y] == 'G' ||
		game->map->map[x][y] == EXIT)
		return (0);
	return (1);
}

void	get_next_position(t_game *game, t_ghost *ghost, int *new_x, int *new_y)
{
	int	dx;
	int	dy;
	int	directions[4][2];
	int	random_index;

	directions[0][0] = 0;
	directions[0][1] = -1;
	directions[1][0] = 1;
	directions[1][1] = 0;
	directions[2][0] = 0;
	directions[2][1] = 1;
	directions[3][0] = -1;
	directions[3][1] = 0;
	dx = ghost->x - ghost->last_pos->x;
	dy = ghost->y - ghost->last_pos->y;
	if (!can_move_to(game, ghost->x + dx, ghost->y + dy))
	{
		random_index = get_random_number(4);
		dx = directions[random_index][0];
		dy = directions[random_index][1];
	}
	*new_x = ghost->x + dx;
	*new_y = ghost->y + dy;
}

void	handle_ghost_render(t_game *game, int i, int j)
{
	int	k;

	k = 0;
	while (game->ghosts->ghost[k] && !(game->ghosts->ghost[k]->x == i
			&& game->ghosts->ghost[k]->y == j))
		k++;
	if (game->ghosts->ghost[k])
		gui_printer(game, j, i, game->ghosts->ghost[k]->current_ptr);
}
