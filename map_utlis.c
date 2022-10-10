/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:45:41 by mealjnei          #+#    #+#             */
/*   Updated: 2022/10/05 18:14:11 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_t(t_game **game)
{
	int	x;

	x = 0;
	while ((*game)->map.m_split[0][x])
	{
		if ((*game)->map.m_split[0][x] != '1')
			_err(*game, "There's error first line map");
		x++;
	}
	(*game)->map.width = x;
}

void	_al(char mid, char first_col, t_game *game)
{
	if (first_col != '1')
		_err(game, "There's error first line map");
	if (mid != '1' && mid != '0' && mid != 'C' && mid != 'P' && mid != 'E')
		_err(game, "There's invalid char in the map");
}

void	check_map_m(t_game **game)
{
	int	i;
	int	x;

	i = 1;
	while ((*game)->map.m_split[i])
	{
		x = 0;
		while ((*game)->map.m_split[i][x])
		{
			_al((*game)->map.m_split[i][x], (*game)->map.m_split[i][0], *game);
			if ((*game)->map.m_split[i][x + 1] == '\0')
				if ((*game)->map.m_split[i][x] != '1')
					_err(*game, "Error last column mid");
			if ((*game)->map.m_split[i][x] == 'P')
				(*game)->player++;
			if ((*game)->map.m_split[i][x] == 'E')
				(*game)->exit++;
			if ((*game)->map.m_split[i][x] == 'C')
				(*game)->n_coins++;
			x++;
		}
		if (x != (*game)->map.width)
			_err(*game, "Lines are not equal");
		i++;
	}
}

void	check_map_b(t_game **game)
{
	int	x;
	int	i;

	i = (*game)->map.height - 1;
	x = 0;
	while ((*game)->map.m_split[i][x])
	{
		if ((*game)->map.m_split[i][x] != '1')
			_err(*game, "There's error first line map");
		x++;
	}
	if (x != (*game)->map.width)
		_err(*game, "There's error lines are no equal");
}

int	check_map(t_game *game)
{
	char	*str;
	int		fd;

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
	game->map.m_split = ft_split(game->map.map, '\n');
	if (!(game->map.m_split))
		return (0);
	game->map.height = count_words(game->map.map, '\n');
	check_map_t(&game);
	check_map_b(&game);
	check_map_m(&game);
	check_err(game);
	return (1);
}