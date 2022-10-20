/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:42:10 by mealjnei          #+#    #+#             */
/*   Updated: 2022/10/17 18:17:49 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_free(t_game *game)
{
	int	i;

	i = 0;
	if (game->map->m_s)
	{
		while (game->map->m_s[i])
		{
			free(game->map->m_s[i]);
			game->map->m_s[i] = NULL;
			i++;
		}
	}
	if (game->map->map)
	{
		free(game->map->map);
		game->map->map = NULL;
	}
	if (game->map)
	{
		free(game->map);
		game->map = NULL;
	}
}

void	_err(t_game *game, char *str)
{
	ft_putendl_fd(str, 2);
	my_free(game);
	exit(EXIT_FAILURE);
}

void	_init(t_game *game, char **av)
{
	if (ft_strnstr())
	game->av = av;
	game->map = ft_calloc(1, sizeof(t_map));
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
	game->n_steps = 0;
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
