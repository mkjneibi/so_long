/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:28:37 by mealjnei          #+#    #+#             */
/*   Updated: 2022/09/28 16:42:45 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_window(int key, t_game *f)
{
	if (key == 12)
	{
		exit(1);
	}
	return (0);
}

void	so_long(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 560, 620, "42game");
	mlx_key_hook(game->win, exit_window, game);
	mlx_loop(game->mlx);

	// game->i =
	// game->img;
}

int main(int ac, char **av)
{
	t_game game;

	if (ac != 2)
	{
		ft_putstr("Enter the map name \n");
		return (0);
	}
	so_long(&game);
}