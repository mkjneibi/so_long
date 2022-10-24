/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:48:55 by mealjnei          #+#    #+#             */
/*   Updated: 2022/10/24 12:08:59 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"

# ifdef __MACH__
#  define A_KEY 0
#  define D_KEY 2
#  define S_KEY 1
#  define W_KEY 13
#  define ESC_KEY 53
# endif

typedef struct s_map
{
	int		width;
	int		height;
	char	**m_s;
	char	*map;
}			t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	char		**av;
	int			n_coins;
	int			end_game;
	int			player;
	int			exit;
	int			error;
	int			i_width;
	int			i_height;
	int			x;
	int			y;
	int			p_x;
	int			p_y;
	void		*player_ptr;
	void		*block_ptr;
	void		*coins_ptr;
	void		*wall_ptr;
	void		*door_ptr;
	int			n_steps;
	int			hash_map[256][256];
	int			player_x;
	int			player_y;
}				t_game;

void	esc_err(t_game *game, char *str);
void	player_utlis(t_game *game, int x, int y);
void	_err(t_game *game, char *str);
void	my_quit(t_game *game);
void	my_free(t_game *game);
void	check_err(t_game *game);
void	check_map_m(t_game **game);
void	check_map_b(t_game **game);
int		check_map(t_game *game);
int		check_map3(t_game *game);
int		check_valid_path(int y, int x, t_game *game);
int		valid(int x, int y, t_game *game);
void	_al(char mid, char first_col, t_game *game);
void	plot_player(char c, t_game *game);
void	plotting(char c, t_game *game);
void	plot_map(t_game *game);
void	so_long(t_game *game);
void	_init(t_game *game, char **av);
int		exit_window(int key, t_game *game);
void	end_game(t_game *game);
void	_x_moves_down(t_game *game);
void	_x_moves_up(t_game *game);
void	_y_moves_down(t_game *game);
void	_y_moves_up(t_game *game);
void	a_key(t_game *game);
void	d_key(t_game *game);
void	s_key(t_game *game);
void	w_key(t_game *game);

#endif
