/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_init_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:16:59 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/23 00:54:10 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	*load_img(t_game *game, char *path)
{
	int	w;
	int	h;

	return (mlx_xpm_file_to_image(game->ressources->mlx_ptr, path, &w, &h));
}

void	init_player_ressources(t_game *game)
{
	game->ressources->player_right_ptr = load_img(game, "./img/player.xpm");
	game->ressources->player_top_ptr = load_img(game, "./img/player-top.xpm");
	game->ressources->player_bottom_ptr = load_img(game, "./img/player-b.xpm");
	game->ressources->player_ptr = load_img(game, "./img/player-right.xpm");
	game->ressources->player_close_ptr = load_img(game, "./img/player-c.xpm");
	if (!game->ressources->player_right_ptr || !game->ressources->player_top_ptr
		|| !game->ressources->player_bottom_ptr
		|| !game->ressources->player_ptr || !game->ressources->player_close_ptr)
	{
		ft_putstr_fd("ERROR\nImg player\n", 2);
		exit_game(game, -1);
	}
}

void	init_texture_ressources(t_game *game)
{
	game->ressources->wall_ptr = load_img(game, "./img/Wall.xpm");
	game->ressources->item_ptr = load_img(game, "./img/item.xpm");
	game->ressources->exit_ptr = load_img(game, "./img/exit.xpm");
	game->ressources->piece_ptr = load_img(game, "./img/piece.xpm");
	game->ressources->game_lose_ptr = load_img(game, "./img/lose.xpm");
	game->ressources->game_win_ptr = load_img(game, "./img/win.xpm");
	if (!game->ressources->wall_ptr || !game->ressources->item_ptr
		|| !game->ressources->exit_ptr
		|| !game->ressources->piece_ptr || !game->ressources->game_lose_ptr
		|| !game->ressources->game_win_ptr)
	{
		ft_putstr_fd("ERROR\nImg texture\n", 2);
		exit_game(game, -1);
	}
}

void	init_ressources(t_game *game)
{
	game->ressources = (t_ressources *)malloc(sizeof(t_ressources));
	game->ressources->mlx_ptr = mlx_init();
	game->ressources->win_ptr = mlx_new_window(game->ressources->mlx_ptr,
			(game->map->y * 50), (game->map->x * 50), "So Long");
	if (!game->ressources->mlx_ptr || !game->ressources->win_ptr)
		return ;
	init_player_ressources(game);
	init_texture_ressources(game);
}
