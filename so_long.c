/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:28:37 by mealjnei          #+#    #+#             */
/*   Updated: 2022/09/30 19:41:43 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_window(int key, t_game *game)
{
	int x = 25;
	if (key == 53)
		exit(1);
	// if (key == A_KEY)
	// if (key == D_KEY)
	// if (key == W_KEY)
	// if (key == S_KEY)
	return (0);
}

void	so_long(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 800, 700, "42game");
	mlx_hook(game->win, 2, 1L << 0, exit_window, game);
	mlx_loop(game->mlx);
	// game->i =
	// game->img;
}

void	_init_map(t_map *map)
{
	map->height = 0;
	map->width = 1;
	map->player = NULL;
	map->coins = NULL;
	map->door = NULL;
	map->block = NULL;
	map->wall = NULL;
}

void	_init(t_game *game, char **av)
{
	t_map	map;

	game->av = av;
	_init_map(&map);
	game->player = -1;
	game->exit = -1;
	game->error = -1;
	game->n_coins = -1;
	game->end_game = -1;
}

void	check_map3(t_game *game)
{
	int	x;
	int i;

	i = game->map.height - 1;
	x = 0;
	while (game->map.map_split[i][x])
	{
		if (game->map.map_split[i][x] != '1')
		{
			ft_putendl_fd("There's error first line map", 2);
			exit(EXIT_FAILURE);
		}
		x++;
	}
	if (x != game->map.width)
	{
		ft_putendl_fd("There's error lines are no equal", 2);
		exit(EXIT_FAILURE);
	}
}

void	check_map2(t_game *game)
{
	int	x;

	x = 0;
	while (game->map.map_split[0][x])
	{
		if (game->map.map_split[0][x] != '1')
		{
			ft_putendl_fd("There's error first line map", 2);
			exit(EXIT_FAILURE);
		}
		x++;
	}
	game->map.width = x;
}

int	check_map(t_game *game)
{
	char 	*str;
	int 	fd;

	fd = open(game->av[1], O_RDONLY);
	if (fd < 0)
		return (0);
	str = get_next_line(fd);
	game->map.map = ft_strdup("");
	while (str)
	{
		game->map.map = ft_strjoin_gnl(game->map.map, str);
		free(str);
		str = get_next_line(fd);
	}
	game->map.map_split = ft_split(game->map.map, '\n');
	if (!(game->map.map_split))
		return (0);
	game->map.height = count_words(game->map.map, '\n');

	return (1);
}

int main(int ac, char **av)
{
	t_game game;

	if (ac != 2)
	{
		ft_putstr("Enter the map name \n");
		return (0);
	}
	_init(&game, av);
	if (!(check_map(&game)))
	{
		ft_putstr("Invalid map \n");
		return (0);
	}
	check_map2(&game);
	check_map3(&game);
	ft_printf("%s \n", game.map.map);
	// so_long(&game);
}