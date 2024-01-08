/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_ressources.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:19:19 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/22 11:21:24 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	close_window(t_game *game)
{
	exit_game(game, 1);
	return (0);
}

void	exit_ressources_player(t_ressources *ressources)
{
	if (ressources->player_ptr)
		mlx_destroy_image(ressources->mlx_ptr, ressources->player_ptr);
	if (ressources->player_top_ptr)
		mlx_destroy_image(ressources->mlx_ptr, ressources->player_top_ptr);
	if (ressources->player_bottom_ptr)
		mlx_destroy_image(ressources->mlx_ptr, ressources->player_bottom_ptr);
	if (ressources->player_right_ptr)
		mlx_destroy_image(ressources->mlx_ptr, ressources->player_right_ptr);
	if (ressources->player_close_ptr)
		mlx_destroy_image(ressources->mlx_ptr, ressources->player_close_ptr);
}

void	exit_ressources_ghost(t_ressources *ressources)
{
	if (ressources->ghost_top_ptr)
		mlx_destroy_image(ressources->mlx_ptr, ressources->ghost_top_ptr);
	if (ressources->ghost_bottom_ptr)
		mlx_destroy_image(ressources->mlx_ptr, ressources->ghost_bottom_ptr);
	if (ressources->ghost_left_ptr)
		mlx_destroy_image(ressources->mlx_ptr, ressources->ghost_left_ptr);
	if (ressources->ghost_right_ptr)
		mlx_destroy_image(ressources->mlx_ptr, ressources->ghost_right_ptr);
}

void	exit_ressources(t_ressources *ressources)
{
	exit_ressources_player(ressources);
	exit_ressources_ghost(ressources);
	if (ressources->wall_ptr)
		mlx_destroy_image(ressources->mlx_ptr, ressources->wall_ptr);
	if (ressources->item_ptr)
		mlx_destroy_image(ressources->mlx_ptr, ressources->item_ptr);
	if (ressources->exit_ptr)
		mlx_destroy_image(ressources->mlx_ptr, ressources->exit_ptr);
	if (ressources->piece_ptr)
		mlx_destroy_image(ressources->mlx_ptr, ressources->piece_ptr);
	if (ressources->game_lose_ptr)
		mlx_destroy_image(ressources->mlx_ptr, ressources->game_lose_ptr);
	if (ressources->game_win_ptr)
		mlx_destroy_image(ressources->mlx_ptr, ressources->game_win_ptr);
	if (ressources->win_ptr)
	{
		mlx_clear_window(ressources->mlx_ptr, ressources->win_ptr);
		mlx_destroy_window(ressources->mlx_ptr, ressources->win_ptr);
		mlx_destroy_display(ressources->mlx_ptr);
		free(ressources->mlx_ptr);
	}
	free(ressources);
}
