/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:31:59 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/22 11:34:50 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

t_game	*set_game(t_game *game, t_map *map, t_status *status, t_ghosts *ghosts)
{
	game->map = map;
	game->status = status;
	game->move_cpt = 0;
	game->frame_count = 0;
	game->ghosts = ghosts;
	game->score = 0;
	return (game);
}

t_game	*init_game(char *str)
{
	t_map		*map;
	t_status	*status;
	t_game		*game;
	t_ghosts	*ghosts;
	int			i;

	if (!str)
		return (NULL);
	game = malloc(sizeof(t_game));
	map = init_map(str);
	if (!game || !map)
		return (NULL);
	status = init_status(map);
	if (!status)
		return (NULL);
	ghosts = init_ghosts();
	if (!ghosts)
		return (NULL);
	i = -1;
	while (++i < 4)
		ghosts->ghost[i] = set_ghost(map);
	game = set_game(game, map, status, ghosts);
	if (!game)
		return (NULL);
	return (game);
}
