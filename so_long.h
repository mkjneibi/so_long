/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:48:55 by mealjnei          #+#    #+#             */
/*   Updated: 2022/09/30 17:37:47 by mealjnei         ###   ########.fr       */
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
	int 	height;
	char	**map_split;
	char	*map;
	void	*player;
	void	*block;
	void	*coins;
	void	*wall;
	void	*door;
}	       t_map;

typedef struct	s_game
{
	void		*mlx;
    void		*win;
	t_map		map;
	char		**av;
	int	 		n_coins;
	int		 	end_game;
	int			player;
	int		 	exit;
	int			error;
}           t_game;

#endif