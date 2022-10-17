/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:47:43 by mealjnei          #+#    #+#             */
/*   Updated: 2022/10/17 17:51:38 by mealjnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_al(char mid, char first_col, t_game *game)
{
	if (first_col != '1')
		_err(game, "There's error first line map");
	if (mid != '1' && mid != '0' && mid != 'C' && mid != 'P' && mid != 'E')
		_err(game, "There's invalid char in the map");
}
