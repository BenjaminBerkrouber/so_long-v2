/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:03:34 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/23 08:04:56 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_str_only_contains(const char *str, const char *chars)
{
	while (*str != '\n')
	{
		if (!ft_strchr(chars, *str))
			return (0);
		str++;
	}
	return (1);
}

int	check_element(char c, int *element)
{
	if (c && (*element == 1))
		return (0);
	else if (c)
		*element = 1;
	return (1);
}

int	check_element_exist(char *str, t_map *map)
{
	while (*str)
	{
		if (*str == EXIT && !check_element(*str, &map->e))
		{
			ft_putstr_fd("Error\nmany exits were found\n", 2);
			return (0);
		}
		if (*str == PLAYER && !check_element(*str, &map->p))
		{
			ft_putstr_fd("Error\nmany players were found\n", 2);
			return (0);
		}
		if (*str == ITEMS)
			map->c++;
		str++;
	}
	return (1);
}

int	is_valide_file(char *file_name)
{
	int	size;

	size = ft_strlen(file_name);
	if (size < 6)
		return (0);
	if (ft_strncmp(".ber", &(file_name[ft_strlen(file_name) - 4]),
			ft_strlen(file_name)))
		return (0);
	return (1);
}

int	check_walls(char *line)
{
	if (!line || !ft_str_only_contains(line, "1"))
	{
		ft_putstr_fd("Error\nmap not surrounded by walls\n", 2);
		return (0);
	}
	return (1);
}
