/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 02:51:12 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/23 02:51:17 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	handle_key_up(t_game *game)
{
	game->status->player->current_ptr = game->ressources->player_top_ptr;
	move_player(game, 0, -1);
}

void	handle_key_down(t_game *game)
{
	game->status->player->current_ptr = game->ressources->player_bottom_ptr;
	move_player(game, 0, 1);
}

void	handle_key_left(t_game *game)
{
	game->status->player->current_ptr = game->ressources->player_ptr;
	move_player(game, -1, 0);
}

void	handle_key_right(t_game *game)
{
	game->status->player->current_ptr = game->ressources->player_right_ptr;
	move_player(game, 1, 0);
}

void	handle_key_esc(t_game *game)
{
	exit_game(game, 1);
}
