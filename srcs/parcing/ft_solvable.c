/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solvable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:38:14 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/28 11:38:17 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	flood_fill(t_game *game, t_coords corr, int **visited, t_dfs_info *info)
{
	if (corr.x < 0 || corr.x >= game->map->x
		|| corr.y < 0 || corr.y >= game->map->y
		|| visited[corr.x][corr.y] || game->map->map[corr.x][corr.y] == WALL)
		return ;
	visited[corr.x][corr.y] = 1;
	if (game->map->map[corr.x][corr.y] == EXIT)
		info->exit_reached++;
	if (game->map->map[corr.x][corr.y] == ITEMS)
		info->items_collected++;
	flood_fill(game, (t_coords){corr.x + 1, corr.y}, visited, info);
	flood_fill(game, (t_coords){corr.x - 1, corr.y}, visited, info);
	flood_fill(game, (t_coords){corr.x, corr.y + 1}, visited, info);
	flood_fill(game, (t_coords){corr.x, corr.y - 1}, visited, info);
}

int	**alloc_visited(t_game *game)
{
	int	i;
	int	**visited;

	visited = ft_calloc(sizeof(int *), game->map->x);
	if (!visited)
		return (0);
	i = 0;
	while (i < game->map->x)
	{
		visited[i] = ft_calloc(sizeof(int), game->map->y);
		if (!visited[i])
			return (0);
		i++;
	}
	return (visited);
}

void	free_visited(int **visited, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->x)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

int	is_solve(t_game *game)
{
	int			**visited;
	t_coords	corr;
	t_dfs_info	info;

	visited = alloc_visited(game);
	info.exit_reached = 0;
	info.items_collected = 0;
	corr.x = game->status->player->y;
	corr.y = game->status->player->x;
	flood_fill(game, corr, visited, &info);
	free_visited(visited, game);
	if (info.items_collected != game->status->items->nbr_item)
		return (0);
	if (info.exit_reached < 1)
		return (0);
	return (1);
}
