/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:10:56 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/23 02:54:57 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	handle_player_render(t_game *game, int i, int j)
{
	void	*player_img;

	if (game->status->player->is_close)
		player_img = game->ressources->player_close_ptr;
	else
		player_img = game->status->player->current_ptr;
	gui_printer(game, j, i, player_img);
}

t_player	*set_player(t_player *player, int x, int y, int life)
{
	player->x = y;
	player->y = x;
	player->life = life;
	player->item_collected = 0;
	player->is_close = 0;
	player->current_ptr = NULL;
	return (player);
}

t_player	*init_player(int x, int y)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player = set_player(player, x, y, 5);
	return (player);
}
