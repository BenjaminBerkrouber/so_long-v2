/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:05:50 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/22 11:05:58 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	exit_map(t_map *map)
{
	char	**area;

	area = map->map;
	while (*area)
	{
		free(*area);
		area++;
	}
	free(map->map);
	free(map);
}
