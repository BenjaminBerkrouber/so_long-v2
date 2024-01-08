/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_item.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:02:03 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/22 12:05:37 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	get_number_item(char **str)
{
	int	i;
	int	j;
	int	cpt;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == ITEMS)
				cpt++;
			j++;
		}
		i++;
	}
	return (cpt);
}

t_item	*set_item(t_item *item, int x, int y, int is_loot)
{
	item->is_loot = is_loot;
	item->x = x;
	item->y = y;
	return (item);
}

t_items	*init_items(t_map *map)
{
	t_items	*items;
	int		nbr_item;
	int		i;

	items = malloc(sizeof(t_items));
	nbr_item = get_number_item(map->map);
	if (!items)
		return (NULL);
	items->item = malloc(sizeof(t_item *) * nbr_item);
	if (!items->item)
	{
		free(items);
		return (NULL);
	}
	i = -1;
	while (++i < nbr_item)
		items->item[i] = NULL;
	nbr_item = get_number_item(map->map);
	items->nbr_item = nbr_item;
	return (items);
}

t_item	*init_item(int x, int y)
{
	t_item	*item;

	item = malloc(sizeof(t_item));
	if (!item)
		return (NULL);
	item->x = x;
	item->y = y;
	item->is_loot = 0;
	return (item);
}
