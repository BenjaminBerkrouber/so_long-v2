/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:52:26 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/28 17:53:39 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSING_H
# define FT_PARSING_H

typedef struct s_dfs_info
{
	int	items_collected;
	int	exit_reached;
	int	*visited;
}	t_dfs_info;

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

int		init_parcing(char *path);
int		ft_str_only_contains(const char *str, const char *chars);
int		check_element(char c, int *element);
int		check_element_exist(char *str, t_map *map);
int		is_valide_file(char *file_name);
int		is_solve(t_game *game);
int		check_walls(char *line);
void	free_gnl(int fd);
int		process_map_line(int fd, size_t size, t_map *map, char **last);
#endif
