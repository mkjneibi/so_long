/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xy_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:52:25 by mealjnei          #+#    #+#             */
/*   Updated: 2022/10/17 14:14:39 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    _x_moves_down(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->block_ptr, game->p_x, game->p_y);
	game->map->m_split[(game->p_y) / 64][(game->p_x - 64) / 64] = '0';
	game->p_x -= 64;
	mlx_put_image_to_window(game->mlx, game->win,
		game->block_ptr, game->p_x, game->p_y);
	mlx_put_image_to_window(game->mlx, game->win,
		game->player_ptr, game->p_x, game->p_y);
	game->end_game++;
	game->n_steps++;
}

void    _x_moves_up(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->block_ptr, game->p_x, game->p_y);
	game->map->m_split[(game->p_y) / 64][(game->p_x + 64) / 64] = '0';
	game->p_x += 64;
	mlx_put_image_to_window(game->mlx, game->win,
		game->block_ptr, game->p_x, game->p_y);
	mlx_put_image_to_window(game->mlx, game->win,
		game->player_ptr, game->p_x, game->p_y);
	game->end_game++;
	game->n_steps++;
}

void    _y_moves_down(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->block_ptr, game->p_x, game->p_y);
	game->map->m_split[(game->p_y + 64) / 64][(game->p_x) / 64] = '0';
	game->p_y += 64;
	mlx_put_image_to_window(game->mlx, game->win,
		game->block_ptr, game->p_x, game->p_y);
	mlx_put_image_to_window(game->mlx, game->win,
		game->player_ptr, game->p_x, game->p_y);
	game->end_game++;
	game->n_steps++;
}

void    _y_moves_up(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->block_ptr, game->p_x, game->p_y);
	game->map->m_split[(game->p_y - 64) / 64][(game->p_x) / 64] = '0';
	game->p_y -= 64;
	mlx_put_image_to_window(game->mlx, game->win,
		game->block_ptr, game->p_x, game->p_y);
	mlx_put_image_to_window(game->mlx, game->win,
		game->player_ptr, game->p_x, game->p_y);
	game->end_game++;
	game->n_steps++;
}

void	end_game(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->block_ptr, game->p_x, game->p_y);
	game->p_x -= 64;
	game->n_steps++;
	my_free(game);
	mlx_destroy_image(game->mlx, game->wall_ptr);
	mlx_destroy_image(game->mlx, game->player_ptr);
	mlx_destroy_image(game->mlx, game->coins_ptr);
	mlx_destroy_image(game->mlx, game->door_ptr);
	mlx_destroy_image(game->mlx, game->block_ptr);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}