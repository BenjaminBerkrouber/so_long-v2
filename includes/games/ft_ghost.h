/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ghost.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:45:43 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/28 17:47:10 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GHOST_H
# define FT_GHOST_H

typedef struct s_corr
{
	int	x;
	int	y;
}	t_corr;

typedef struct s_ghost
{
	int		x;
	int		y;
	char	last_case;
	t_corr	*last_pos;
	void	*current_ptr;
}	t_ghost;

typedef struct s_ghosts
{
	t_ghost	**ghost;
	int		nbr_ghosts;
}	t_ghosts;

t_ghosts	*init_ghosts(void);
t_ghost		*init_ghost(int x, int y);
#endif
