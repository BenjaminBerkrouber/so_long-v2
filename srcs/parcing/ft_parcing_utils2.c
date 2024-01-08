/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:15:22 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/23 08:15:24 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	free_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

int	process_map_line(int fd, size_t size, t_map *map, char **last)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (!is_valide_line(line, size, map))
		{
			free(line);
			return (0);
		}
		free(*last);
		*last = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}
