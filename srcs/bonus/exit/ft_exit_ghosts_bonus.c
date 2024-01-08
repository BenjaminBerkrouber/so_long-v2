/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_ghosts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:04:24 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/22 11:04:51 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	exit_ghost(t_ghost *ghost)
{
	if (!ghost)
		return ;
	free(ghost->last_pos);
	free(ghost);
}

void	exit_ghosts(t_ghosts *ghosts)
{
	int	i;

	if (!ghosts)
		return ;
	i = 0;
	while (i < 4)
	{
		if (ghosts->ghost[i])
			exit_ghost(ghosts->ghost[i]);
		i++;
	}
	free(ghosts->ghost);
	free(ghosts);
}
