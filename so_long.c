/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:28:37 by mealjnei          #+#    #+#             */
/*   Updated: 2022/10/10 13:42:14 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	plot_player(char c, t_game *game)
{
	if (c == 'P')
	{
		game->p_x = game->x;
		game->p_y = game->y;
		mlx_put_image_to_window(game->mlx, game->win, game->map->block, game->x, game->y);
		mlx_put_image_to_window(game->mlx, game->win, game->map->player, game->x, game->y);
	}
}

void	plotting(char c, t_game *game)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->map->wall, game->x, game->y);
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->map->block, game->x, game->y);
	if (c == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->map->block, game->x, game->y);
		mlx_put_image_to_window(game->mlx, game->win, game->map->door, game->x, game->y);
	}
	if (c == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->map->block, game->x, game->y);
		mlx_put_image_to_window(game->mlx, game->win, game->map->coins, game->x, game->y);
	}
	plot_player(c, game);
}

void	plot_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map->m_split[y])
	{
		x = 0;
		while (game->map->m_split[y][x])
		{
			// plotting(game->map.m_split[y][x], game);
			game->x += 64;
			x++;
		}
		game->y += 64;
		y++;
	}
}

void	so_long(t_game *game)
{
	int	width;
	int	height;

	width = game->map->width * 64;
	height = game->map->height * 64;
	ft_printf("%d %d\n", width, height);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, width, height, "42game");
	mlx_hook(game->win, 2, 1L << 0, exit_window, game);
	game->map->player = mlx_xpm_file_to_image(game->mlx, "./img/mario.xpm", &game->i_width, &game->i_height);
	game->map->block = mlx_xpm_file_to_image(game->mlx, "./img/block.xpm", &game->i_width, &game->i_height);
	game->map->coins = mlx_xpm_file_to_image(game->mlx, "./img/coins.xpm", &game->i_width, &game->i_height);
	game->map->wall = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm", &game->i_width, &game->i_height);
	game->map->door = mlx_xpm_file_to_image(game->mlx, "./img/door.xpm", &game->i_width, &game->i_height);
	plot_map(game);
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
	// if (!(check_map(&game)))
	// {
	// 	_err(&game, "Invalid map \n");
	// 	return (0);
	// }
	// so_long(&game);
}