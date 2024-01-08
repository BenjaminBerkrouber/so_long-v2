/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:51:51 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/28 17:52:04 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STATUS_H
# define FT_STATUS_H

# include "ft_player.h"
# include "ft_item.h"
# include "ft_exit.h"

typedef struct s_status
{
	t_player	*player;
	t_exit		*exit;
	t_items		*items;
}	t_status;

t_status	*init_status(t_map *map);

#endif
