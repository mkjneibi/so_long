/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utlis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:45:08 by mealjnei          #+#    #+#             */
/*   Updated: 2022/10/16 13:52:06 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	a_key(int key, t_game *game)
{
		if (game->map->m_split[(game->p_y) / 64][(game->p_x - 64) / 64] == 'C')
			_x_moves_down(game);
		else if (game->map->m_split[(game->p_y) / 64][(game->p_x - 64) / 64] == 'E' &&
				game->end_game == game->n_coins)
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
				ft_printf("%d\n",game->n_steps);
			}
}

void	d_key(int key, t_game *game)
{
		if (game->map->m_split[(game->p_y) / 64][(game->p_x + 64) / 64] == 'C')
			_x_moves_up(game);
		else if (game->map->m_split[(game->p_y) / 64][(game->p_x + 64) / 64] == 'E' &&
				game->end_game == game->n_coins)
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
				ft_printf("%d\n",game->n_steps);
			}
}

void	s_key(int key, t_game *game)
{
		if (game->map->m_split[(game->p_y + 64) / 64][(game->p_x) / 64] == 'C')
			_y_moves_down(game);
		else if (game->map->m_split[(game->p_y + 64) / 64][(game->p_x) / 64] == 'E' &&
				game->end_game == game->n_coins)
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
				ft_printf("%d\n",game->n_steps);
			}
}

void	w_key(int key, t_game *game)
{
		if (game->map->m_split[(game->p_y - 64) / 64][(game->p_x) / 64] == 'C')
			_y_moves_up(game);
		else if (game->map->m_split[(game->p_y - 64) / 64][(game->p_x) / 64] == 'E' &&
				game->end_game == game->n_coins)
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
				ft_printf("%d\n",game->n_steps);
			}
}

int	exit_window(int key, t_game *game)
{
	if (key == ESC_KEY)
		exit(1);
	if (key == A_KEY)
		a_key(key, game);
	if (key == D_KEY)
		d_key(key, game);
	if (key == S_KEY)
		s_key(key, game);
	if (key == W_KEY)
		w_key(key, game);
	return (0);
}
