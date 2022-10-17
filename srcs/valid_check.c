#include "so_long.h"

int valid(int x, int y, t_game *game)
{
	if ((game)->map->m_split[y][x] == '1' || (game)->hash_map[y][x] == 1)
		return (0);
	return (1);
}

int check_valid_path(int y, int x, t_game *game)
{
	if ((game)->map->m_split[y][x] == 'E')
		return (1);
	(game)->hash_map[y][x] = 1;
	if (valid(x, y - 1, game)) // up
		if (check_valid_path(y - 1, x, game))
			return (1);
	if (valid(x, y + 1, game)) //down
		if (check_valid_path(y + 1, x, game))
			return (1);
	if (valid(x + 1, y, game)) //right
		if (check_valid_path(y, x + 1, game))
			return (1);
	if (valid(x - 1, y, game)) //left
		if (check_valid_path(y, x - 1, game))
			return (1);
	return (0);
}

int check_map3(t_game *game)
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
	if (check_valid_path(y ,x ,game))
		return (0);
	return (1);
}