/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:42:10 by mealjnei          #+#    #+#             */
/*   Updated: 2022/10/10 13:43:10 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_err(t_game *game, char *str)
{
		ft_putendl_fd(str, 2);
		// freestruct;
		exit(EXIT_FAILURE);
}

t_map	*_init_map()
{
	t_map	*map;

	map->height = 0;
	map->width = 1;
	map->player = NULL;
	map->coins = NULL;
	map->door = NULL;
	map->block = NULL;
	map->wall = NULL;
	return (map);
}

void	_init(t_game *game, char **av)
{
	// t_map	map;

	game->av = av;
	game->map = _init_map();
	game->player = 0;
	game->exit = 0;
	game->error = 0;
	game->n_coins = 0;
	game->end_game = 0;
	game->i_height = 0;
	game->i_width = 0;
	game->x = 0;
	game->y = 0;
	game->p_x = 0;
	game->p_y = 0;
}

void	check_err(t_game *game)
{
	if (game->player != 1)
		_err(game, "Error in number of players");
	if (game->exit != 1)
		_err(game, "Error in number of exits");
	if (game->n_coins <= 0)
		_err(game, "Error in number of coins");
}