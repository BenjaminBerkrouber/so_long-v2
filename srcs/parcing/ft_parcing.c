/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:15:22 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/23 08:15:24 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	is_valide_line(char *line, size_t size, t_map *map)
{
	if (ft_strlen(line) != size)
	{
		ft_putstr_fd("Error\nNo rectangular card\n", 2);
		return (0);
	}
	if (line[0] != '1' || line[size - 2] != '1')
	{
		ft_putstr_fd("Error\nmap not surrounded by walls\n", 2);
		return (0);
	}
	if (!check_element_exist(line, map))
		return (0);
	while (*line)
	{
		if (!ft_str_only_contains(line, "01PEC"))
		{
			ft_putstr_fd("Error\nanother character was found\n", 2);
			return (0);
		}
		line++;
	}
	return (1);
}

int	check_map_elements(t_map *map)
{
	if (map->p != 1)
		ft_putstr_fd("Error\nplayer not found\n", 2);
	else if (map->e != 1)
		ft_putstr_fd("Error\nexit not found\n", 2);
	else if (map->c < 1)
		ft_putstr_fd("Error\nitem(s) not found\n", 2);
	else
		return (1);
	return (0);
}

int	is_valide_map(int fd)
{
	char	*last;
	t_map	map;
	size_t	size;
	char	*line;

	ft_memset(&map, 0, sizeof(map));
	line = get_next_line(fd);
	if (!check_walls(line))
	{
		free(line);
		free_gnl(fd);
		return (0);
	}
	size = ft_strlen(line);
	free(line);
	last = malloc(0);
	if (!process_map_line(fd, size, &map, &last) || !check_walls(last))
	{
		free_gnl(fd);
		free(last);
		return (0);
	}
	free(last);
	free_gnl(fd);
	return (check_map_elements(&map));
}

int	init_parcing(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nconnot open this file\n", 2);
		return (0);
	}
	if (!is_valide_file(file_name))
	{
		ft_putstr_fd("Error\nthe file was not a (.ber)\n", 2);
		return (0);
	}
	if (!is_valide_map(fd))
		return (0);
	close(fd);
	return (1);
}
