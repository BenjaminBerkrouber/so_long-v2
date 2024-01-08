/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:01:09 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/22 12:01:17 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

t_exit	*init_exit(int x, int y)
{
	t_exit	*exit;

	exit = malloc(sizeof(t_exit));
	if (!exit)
		return (NULL);
	exit->x = x;
	exit->y = y;
	exit->open = 0;
	return (exit);
}
