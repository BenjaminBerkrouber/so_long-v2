/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:58:05 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/22 12:00:22 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

t_status	*set_status(t_map *map, t_status *status)
{
	int	i;
	int	j;
	int	item_count;

	item_count = 0;
	i = -1;
	status->items = init_items(map);
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == PLAYER)
				status->player = init_player(i, j);
			else if (map->map[i][j] == EXIT)
				status->exit = init_exit(i, j);
			else if (map->map[i][j] == ITEMS)
			{
				status->items->item[item_count] = init_item(i, j);
				item_count++;
			}
		}
	}
	return (status);
}

t_status	*init_status(t_map *map)
{
	t_status	*status;

	status = malloc(sizeof(t_status));
	if (!status || !map)
		return (NULL);
	status = set_status(map, status);
	if (!status)
		return (NULL);
	return (status);
}
