/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:28:37 by mealjnei          #+#    #+#             */
/*   Updated: 2022/09/28 17:27:46 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_window(int key, t_game *game)
{
	int x = 25;
	if (key == 53)
		exit(1);
	if (key == A_KEY)
	{
		game->x -= x;
		mlx_clear_window(game->mlx, game->win);
		mlx_put_image_to_window(game->mlx,game->win, game->img.img_ptr, game->x, game->y);
	}
	if (key == D_KEY)
	{
		game->x += x;
		mlx_clear_window(game->mlx, game->win);
		mlx_put_image_to_window(game->mlx,game->win, game->img.img_ptr, game->x, game->y);
	}
	if (key == W_KEY)
	{
		game->y -= x;
		mlx_clear_window(game->mlx, game->win);
		mlx_put_image_to_window(game->mlx,game->win, game->img.img_ptr, game->x, game->y);
	}
	if (key == S_KEY)
	{
		game->y += x;
		mlx_clear_window(game->mlx, game->win);
		mlx_put_image_to_window(game->mlx,game->win, game->img.img_ptr, game->x, game->y);
	}
	return (0);
}

void	so_long(t_game *game)
{
	char 	*str;

	str = ft_strdup("./player_2.xpm");
	game->x = 1;
	game->y = 1;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1000, 1000, "42game");
	game->img.img_ptr = mlx_xpm_file_to_image(game->mlx, str, &game->x, &game->y);
	mlx_put_image_to_window(game->mlx,game->win, game->img.img_ptr, game->x, game->y);
	mlx_hook(game->win, 2, 1L << 0, exit_window, game);
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