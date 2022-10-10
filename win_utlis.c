/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:45:08 by mealjnei          #+#    #+#             */
/*   Updated: 2022/10/10 17:51:02 by mealjnei         ###   ########.fr       */
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
		mlx_put_image_to_window(game->mlx, game->win, game->block_ptr, game->p_x, game->p_y);
		game->p_x -= 64;
		mlx_put_image_to_window(game->mlx, game->win, game->block_ptr, game->p_x, game->p_y);
		mlx_put_image_to_window(game->mlx, game->win, game->player_ptr, game->p_x, game->p_y);
	}
	if (key == D_KEY)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->block_ptr, game->p_x, game->p_y);
		game->p_x += 64;
		mlx_put_image_to_window(game->mlx, game->win, game->block_ptr, game->p_x, game->p_y);
		mlx_put_image_to_window(game->mlx, game->win, game->player_ptr, game->p_x, game->p_y);
	}
	if (key == W_KEY)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->block_ptr, game->p_x, game->p_y);
		game->p_y -= 64;
		mlx_put_image_to_window(game->mlx, game->win, game->block_ptr, game->p_x, game->p_y);
		mlx_put_image_to_window(game->mlx, game->win, game->player_ptr, game->p_x, game->p_y);
	}
	if (key == S_KEY)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->block_ptr, game->p_x, game->p_y);
		game->p_y += 64;
		mlx_put_image_to_window(game->mlx, game->win, game->block_ptr, game->p_x, game->p_y);
		mlx_put_image_to_window(game->mlx, game->win, game->player_ptr, game->p_x, game->p_y);
	}
	return (0);
}

void    _x_moves(char c, t_game *game)
{
	
}

void    _y_moves(char c, t_game *game)
{
}