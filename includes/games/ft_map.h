/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:49:14 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/28 17:49:38 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

typedef struct s_map
{
	int		e;
	int		p;
	int		i;
	int		c;
	char	**map;
	int		x;
	int		y;
}	t_map;

t_map	*init_map(char *path);
#endif
