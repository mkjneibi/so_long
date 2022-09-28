/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:48:55 by mealjnei          #+#    #+#             */
/*   Updated: 2022/09/28 17:14:30 by mealjnei         ###   ########.fr       */
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

typedef struct	s_img
{
	void		*img_ptr;
}           t_img;

typedef struct	s_game
{
	void		*mlx;
    void		*win;
    int			i;
	int	 		x;
	int			y;
	t_img       img;
}           t_game;

#endif