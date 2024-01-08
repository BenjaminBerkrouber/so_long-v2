/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 01:05:37 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/23 01:06:43 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"
#include <stdio.h>

void	gui_printer(t_game *game, int x, int y, void *img_ptr)
{
	int	img_x;
	int	img_y;

	img_x = x * 50;
	img_y = y * 50;
	mlx_put_image_to_window(game->ressources->mlx_ptr,
		game->ressources->win_ptr, img_ptr, img_x, img_y);
}

void	redraw_map(t_game *game)
{
	mlx_clear_window(game->ressources->mlx_ptr, game->ressources->win_ptr);
	gui_controller(game);
	aredraw_map(game);
}

void	aredraw_map(t_game *game)
{
	char	move_str[100];

	mlx_clear_window(game->ressources->mlx_ptr, game->ressources->win_ptr);
	gui_controller(game);
	sprintf(move_str, "Moves: %d | item: %d/%d | score: %d",
		game->move_cpt, game->status->player->item_collected,
		game->status->items->nbr_item, game->score);
	mlx_string_put(game->ressources->mlx_ptr,
		game->ressources->win_ptr, 10, 20, 0xFFFFFF, move_str);
}
