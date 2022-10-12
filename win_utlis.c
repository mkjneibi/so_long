/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:45:08 by mealjnei          #+#    #+#             */
/*   Updated: 2022/10/12 12:18:19 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_window(int key, t_game *game)
{
	int x = 25;
	if (key == 53)
		exit(1);
	first_key(key, game);
	second_key(key, game);
	third_key(key, game);
	fourth_key(key, game);
	return (0);
}

void	first_key(int key, t_game *game)
{
	if (key == A_KEY)
	{
		if (game->map->m_split[(game->p_y) / 64][(game->p_x - 64) / 64] == 'C')
			_x_moves_down(game);
		else if (game->map->m_split[(game->p_y) / 64][(game->p_x - 64) / 64] == 'E' &&
				game->exit == game->n_coins)
					end_game(game);
		else if (!(game->map->m_split[game->p_y / 64][(game->p_x - 64) / 64] == '1')
					&& !(game->map->m_split[game->p_y / 64][(game->p_x - 64) / 64] == 'E'))
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->block_ptr, game->p_x, game->p_y);
				game->p_x -= 64;
				mlx_put_image_to_window(game->mlx, game->win,
					game->player_ptr, game->p_x, game->p_y);
				game->n_steps++;
				ft_putnbr(game->n_steps);
				write(1, "\n", 1);
			}
	}
}

void	second_key(int key, t_game *game)
{
	if (key == D_KEY)
	{
		if (game->map->m_split[(game->p_y) / 64][(game->p_x + 64) / 64] == 'C')
			_x_moves_up(game);
		else if (game->map->m_split[(game->p_y) / 64][(game->p_x + 64) / 64] == 'E' &&
				game->exit == game->n_coins)
					end_game(game);
		else if (!(game->map->m_split[game->p_y / 64][(game->p_x + 64) / 64] == '1')
					&& !(game->map->m_split[game->p_y / 64][(game->p_x + 64) / 64] == 'E'))
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->block_ptr, game->p_x, game->p_y);
				game->p_x += 64;
				mlx_put_image_to_window(game->mlx, game->win,
					game->player_ptr, game->p_x, game->p_y);
				game->n_steps++;
				ft_putnbr(game->n_steps);
				write(1, "\n", 1);
			}
	}
}

void	third_key(int key, t_game *game)
{
	if (key == S_KEY)
	{
		if (game->map->m_split[(game->p_y + 64) / 64][(game->p_x) / 64] == 'C')
			_y_moves_down(game);
		else if (game->map->m_split[(game->p_y + 64) / 64][(game->p_x) / 64] == 'E' &&
				game->exit == game->n_coins)
					end_game(game);
		else if (!(game->map->m_split[(game->p_y + 64) / 64][(game->p_x) / 64] == '1')
					&& !(game->map->m_split[(game->p_y + 64) / 64][(game->p_x) / 64] == 'E'))
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->block_ptr, game->p_x, game->p_y);
				game->p_y += 64;
				mlx_put_image_to_window(game->mlx, game->win,
					game->player_ptr, game->p_x, game->p_y);
				game->n_steps++;
				ft_putnbr(game->n_steps);
				write(1, "\n", 1);
			}
	}
}

void	fourth_key(int key, t_game *game)
{
	if (key == W_KEY)
	{
		if (game->map->m_split[(game->p_y - 64) / 64][(game->p_x) / 64] == 'C')
			_y_moves_up(game);
		else if (game->map->m_split[(game->p_y - 64) / 64][(game->p_x) / 64] == 'E' &&
				game->exit == game->n_coins)
					end_game(game);
		else if (!(game->map->m_split[(game->p_y - 64) / 64][(game->p_x) / 64] == '1')
				&& !(game->map->m_split[(game->p_y - 64) / 64][(game->p_x) / 64] == 'E'))
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->block_ptr, game->p_x, game->p_y);
				game->p_y -= 64;
				mlx_put_image_to_window(game->mlx, game->win,
					game->player_ptr, game->p_x, game->p_y);
				game->n_steps++;
				ft_putnbr(game->n_steps);
				write(1, "\n", 1);
			}
	}
}
