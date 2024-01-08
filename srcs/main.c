/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:30:53 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/27 15:31:32 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	is_win(t_status *status)
{
	return (status->player->item_collected == status->items->nbr_item);
}

int	get_random_number(int limits)
{
	static int	counter;
	int			random;

	if (!counter)
		counter = 8;
	counter = counter * 61 + 91;
	random = (counter / 127) % 37;
	return ((unsigned int)random % limits);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_putstr_fd("Error : no arguments given\n", 0);
		return (1);
	}
	if (!init_parcing(argv[1]))
		return (1);
	game = init_game(argv[1]);
	if (!game)
		return (1);
	if (!is_solve(game))
	{
		ft_putstr_fd("Error\nthe map is not solvent\n", 0);
		exit_game(game, -1);
		return (1);
	}
	gui_manager(game);
	return (0);
}
