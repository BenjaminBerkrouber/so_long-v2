/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:06:07 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/22 12:10:28 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

char	*get_map_form_folder(int fd)
{
	char	*str;
	char	*line;
	char	*temp;

	str = NULL;
	line = get_next_line(fd);
	while (line)
	{
		temp = str;
		str = ft_strjoin(str, line);
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	return (str);
}

t_map	*set_map(char *str)
{
	t_map	*map;
	int		i;
	int		j;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = ft_split(str, '\n');
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			j++;
		}
		i++;
	}
	map->x = i;
	map->y = j;
	return (map);
}

t_map	*init_map(char *path)
{
	char	*str;
	int		fd;
	t_map	*map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = get_map_form_folder(fd);
	close(fd);
	map = set_map(str);
	free(str);
	return (map);
}
