/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:06:20 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/22 11:06:34 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	exit_status(t_status *status)
{
	if (!status)
		return ;
	if (status->player)
		free(status->player);
	if (status->exit)
		free(status->exit);
	if (status->items)
		exit_items(status->items);
	free(status);
}
