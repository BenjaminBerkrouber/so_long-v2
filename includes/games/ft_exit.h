/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:43:36 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/28 17:44:07 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXIT_H
# define FT_EXIT_H

typedef struct s_exit
{
	int	x;
	int	y;
	int	open;
}	t_exit;

t_exit	*init_exit(int x, int y);

#endif
