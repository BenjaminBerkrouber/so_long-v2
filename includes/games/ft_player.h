/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:49:56 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/28 17:50:20 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PLAYER_H
# define FT_PLAYER_H

# include "ft_game.h"

typedef struct s_player
{
	int		x;
	int		y;
	int		life;
	int		item_collected;
	int		is_close;
	void	*current_ptr;
}	t_player;

t_player	*init_player(int x, int y);
#endif
