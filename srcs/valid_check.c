/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:38:04 by mealjnei          #+#    #+#             */
/*   Updated: 2022/10/17 17:45:32 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid(int x, int y, t_game *game)
{
	if ((game)->map->m_s[y][x] == '1' || (game)->hash_map[y][x] == 1)
		return (0);
	return (1);
}

int	check_valid_path(int y, int x, t_game *game)
{
	if ((game)->map->m_s[y][x] == 'E')
		return (1);
	(game)->hash_map[y][x] = 1;
	if (valid(x, y - 1, game))
		if (check_valid_path(y - 1, x, game))
			return (1);
	if (valid(x, y + 1, game))
		if (check_valid_path(y + 1, x, game))
			return (1);
	if (valid(x + 1, y, game))
		if (check_valid_path(y, x + 1, game))
			return (1);
	if (valid(x - 1, y, game))
		if (check_valid_path(y, x - 1, game))
			return (1);
	return (0);
}

int	check_map3(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < 255)
	{
		x = 0;
		while (x < 255)
		{
			game->hash_map[y][x] = 0;
			x++;
		}
		y++;
	}
	x = 1;
	y = 1;
	if (check_valid_path(y, x, game))
		return (0);
	return (1);
}
