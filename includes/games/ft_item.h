/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_item.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:48:26 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/28 17:49:03 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITEM_H
# define FT_ITEM_H

typedef struct s_item
{
	int	x;
	int	y;
	int	is_loot;
}	t_item;

typedef struct s_items
{
	t_item	**item;
	int		nbr_item;
}	t_items;

t_items	*init_items(t_map *map);
t_item	*init_item(int x, int y);
#endif
