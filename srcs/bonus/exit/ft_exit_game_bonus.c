/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:17:12 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/23 07:40:00 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	gui_printer_end(t_game *game, int mode)
{
	int		img_x;
	int		img_y;
	void	*img_ptr;

	if (mode == 1 || mode == 2)
	{
		if (mode == 1)
			img_ptr = game->ressources->game_lose_ptr;
		if (mode == 2)
			img_ptr = game->ressources->game_win_ptr;
		img_x = ((game->map->x * 50) / 2) - 75;
		img_y = ((game->map->y * 50) / 2) - 150;
		mlx_put_image_to_window(game->ressources->mlx_ptr,
			game->ressources->win_ptr, img_ptr, img_y, img_x);
		mlx_do_sync(game->ressources->mlx_ptr);
		sleep(2);
	}
}

void	exit_game(t_game *game, int mode)
{
	gui_printer_end(game, mode);
	if (!game)
		return ;
	if (game->map)
		exit_map(game->map);
	if (game->status)
		exit_status(game->status);
	if (game->ghosts)
		exit_ghosts(game->ghosts);
	if (game->ressources)
		exit_ressources(game->ressources);
	free(game);
	exit(1);
}
