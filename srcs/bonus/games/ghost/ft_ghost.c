/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ghost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:13:29 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/22 12:19:29 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

t_corr	*get_free_case(t_map *map)
{
	t_corr	*corr;
	int		x;
	int		y;

	corr = malloc(sizeof(t_corr));
	if (!corr)
		return (NULL);
	x = get_random_number(map->x);
	y = get_random_number(map->y);
	while (map->map[x][y] != FREE)
	{
		x = get_random_number(map->x);
		y = get_random_number(map->y);
	}
	corr->x = x;
	corr->y = y;
	return (corr);
}

t_ghost	*set_ghost(t_map *map)
{
	t_corr	*corr;
	int		x;
	int		y;

	x = 0;
	y = 0;
	corr = get_free_case(map);
	if (!corr)
		return (NULL);
	x = corr->x;
	y = corr->y;
	free(corr);
	map->map[x][y] = GHOST;
	return (init_ghost(x, y));
}

t_ghost	*init_ghost(int x, int y)
{
	t_ghost	*ghost;
	t_corr	*corr;

	ghost = malloc(sizeof(t_ghost));
	if (!ghost)
		return (NULL);
	corr = malloc(sizeof(t_corr));
	if (!corr)
		return (NULL);
	ghost->x = x;
	ghost->y = y;
	ghost->last_case = FREE;
	corr->x = 0;
	corr->y = 0;
	ghost->last_pos = corr;
	return (ghost);
}

t_ghosts	*init_ghosts(void)
{
	t_ghosts	*ghosts;
	int			i;

	ghosts = malloc(sizeof(t_ghosts));
	if (!ghosts)
		return (NULL);
	ghosts->ghost = malloc(sizeof(t_ghost *) * NBR_GHOST);
	if (!ghosts->ghost)
	{
		free(ghosts);
		return (NULL);
	}
	i = 0;
	while (i < (NBR_GHOST - 1))
	{
		ghosts->ghost[i] = NULL;
		i++;
	}
	ghosts->nbr_ghosts = NBR_GHOST;
	return (ghosts);
}
