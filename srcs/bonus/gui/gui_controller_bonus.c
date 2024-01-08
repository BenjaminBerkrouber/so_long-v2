/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 02:36:58 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/23 02:40:37 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	update_animation(t_game *game)
{
	game->frame_count++;
	if (game->frame_count % N == 0)
	{
		update_pos_ghost(game);
		if (game->status->player->is_close)
			game->status->player->is_close = 0;
		else
			game->status->player->is_close = 1;
		redraw_map(game);
	}
	return (0);
}

void	handle_cell_render(t_game *game, int i, int j)
{
	if (game->map->map[i][j] == WALL)
		gui_printer(game, j, i, game->ressources->wall_ptr);
	else if (game->map->map[i][j] == PLAYER)
		handle_player_render(game, i, j);
	else if (game->map->map[i][j] == ITEMS)
		gui_printer(game, j, i, game->ressources->item_ptr);
	else if (game->map->map[i][j] == EXIT)
		gui_printer(game, j, i, game->ressources->exit_ptr);
	else if (game->map->map[i][j] == FREE)
		gui_printer(game, j, i, game->ressources->piece_ptr);
	else if (game->map->map[i][j] == GHOST)
		handle_ghost_render(game, i, j);
}

void	gui_controller(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			handle_cell_render(game, i, j);
			j++;
		}
		i++;
	}
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_UP)
		handle_key_up(game);
	else if (keycode == KEY_DOWN)
		handle_key_down(game);
	else if (keycode == KEY_LEFT)
		handle_key_left(game);
	else if (keycode == KEY_RIGHT)
		handle_key_right(game);
	else if (keycode == KEY_ESC)
		handle_key_esc(game);
	return (0);
}

void	gui_manager(t_game *game)
{
	int	i;

	i = 0;
	init_ressources(game);
	game->status->player->current_ptr = game->ressources->player_ptr;
	while (i < NBR_GHOST)
	{
		game->ghosts->ghost[i]->current_ptr = game->ressources->ghost_left_ptr;
		i++;
	}
	gui_controller(game);
	mlx_hook(game->ressources->win_ptr, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->ressources->win_ptr, 17, 1L << 17, close_window, game);
	mlx_loop_hook(game->ressources->mlx_ptr, update_animation, game);
	mlx_loop(game->ressources->mlx_ptr);
}
