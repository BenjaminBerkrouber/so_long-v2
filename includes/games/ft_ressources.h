/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ressources.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:50:38 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/28 17:51:37 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RESSOURCES_H
# define FT_RESSOURCES_H

typedef struct s_ressources
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall_ptr;
	void	*item_ptr;
	void	*exit_ptr;
	void	*piece_ptr;
	void	*game_lose_ptr;
	void	*game_win_ptr;
	void	*player_ptr;
	void	*player_close_ptr;
	void	*player_top_ptr;
	void	*player_bottom_ptr;
	void	*player_right_ptr;
	void	*ghost_top_ptr;
	void	*ghost_bottom_ptr;
	void	*ghost_left_ptr;
	void	*ghost_right_ptr;
	void	*back_ptr;
}	t_ressources;

void	exit_items(t_items *items);
void	exit_ghosts(t_ghosts *ghosts);
void	exit_status(t_status *status);
void	exit_map(t_map *map);
void	exit_ressources(t_ressources *ressources);
#endif
