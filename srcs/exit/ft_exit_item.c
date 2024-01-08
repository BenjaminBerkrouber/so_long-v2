/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_item.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:05:15 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/22 11:05:31 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	exit_items(t_items *items)
{
	int	i;

	if (!items)
		return ;
	i = 0;
	while (i < items->nbr_item)
	{
		free(items->item[i]);
		i++;
	}
	free(items->item);
	free(items);
}
