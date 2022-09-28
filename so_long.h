/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:48:55 by mealjnei          #+#    #+#             */
/*   Updated: 2022/09/28 16:03:04 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "libft/includes/libft.h"
# include "mlx/mlx.h"

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}           t_img;

typedef struct	s_game
{
	void		*mlx;
    void		*win;
    int 		i;
	t_img       img;
}           t_game;

#endif