/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:53:44 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/23 07:53:47 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	up_items_collected(t_game *game)
{
	game->status->player->item_collected++;
	game->score += 10;
	if (is_win(game->status))
		game->status->exit->open = 1;
}

int	check_collision(t_game *game, int new_x, int new_y)
{
	if (game->map->map[new_y][new_x] == WALL ||
		(game->map->map[new_y][new_x] == EXIT && game->status->exit->open != 1))
	{
		return (0);
	}
	return (1);
}

void	update_player_position(t_game *game, int new_x, int new_y)
{
	game->map->map[game->status->player->y][game->status->player->x] = '2';
	game->map->map[new_y][new_x] = PLAYER;
	game->status->player->x = new_x;
	game->status->player->y = new_y;
	game->move_cpt++;
}

void	move_player(t_game *game, int dx, int dy)
{
	int	old_x;
	int	old_y;
	int	new_x;
	int	new_y;

	old_x = game->status->player->x;
	old_y = game->status->player->y;
	new_x = old_x + dx;
	new_y = old_y + dy;
	if (!check_collision(game, new_x, new_y))
		return ;
	if (game->map->map[new_y][new_x] == EXIT && game->status->exit->open)
		exit_game(game, 2);
	if (game->map->map[new_y][new_x] == ITEMS)
		up_items_collected(game);
	if (game->map->map[new_y][new_x] == FREE)
		game->score += 2;
	update_player_position(game, new_x, new_y);
	gui_printer(game, old_x, old_y, game->ressources->piece_ptr);
	gui_printer(game, new_x, new_y, game->ressources->player_ptr);
	aredraw_map(game);
	ft_putnbr_fd(game->move_cpt, 1);
	ft_putstr_fd(" moves\n", 1);
}
