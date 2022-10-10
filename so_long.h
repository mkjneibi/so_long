/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:48:55 by mealjnei          #+#    #+#             */
/*   Updated: 2022/10/10 13:37:05 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "libft/includes/libft.h"
# include "mlx/mlx.h"

# ifdef __MACH__
#  define A_KEY 0
#  define D_KEY 2
#  define S_KEY 1
#  define W_KEY 13
#  define ESC_KEY 53
#  define SPACE_KEY 49
# endif

typedef struct s_map
{
	int		width;
	int		height;
	char	**m_split;
	char	*map;
	void	*player;
	void	*block;
	void	*coins;
	void	*wall;
	void	*door;
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
}				t_game;

void	_err(t_game *game, char *str);
void	_init(t_game *game, char **av);
int		check_map(t_game *game);
int		exit_window(int key, t_game *game);
void	check_err(t_game *game);

#endif