/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:28:37 by mealjnei          #+#    #+#             */
/*   Updated: 2022/10/10 12:32:58 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 800, 700, "42game");
	mlx_hook(game->win, 2, 1L << 0, exit_window, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_putendl_fd("Enter the map name \n", 2);
		return (0);
	}
	_init(&game, av);
	if (!(check_map(&game)))
	{
		_err(&game, "Invalid map \n");
		return (0);
	}
	so_long(&game);
}