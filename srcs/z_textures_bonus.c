/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_textures_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:18:07 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 13:07:20 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_texture(int flag, t_interact *interact, int color)
{
	(void)color;
	if (flag == 1)
		interact->color = checkerboard(interact);
}

int	checkerboard(t_interact *interact)
{
	int			bits_wise;
	int			black;
	int			white;

	bits_wise = (int)abs((int)floor(interact->pos.x)) % 2 ^ \
	(int)abs((int)floor(interact->pos.y)) % 2 ^ \
	(int)abs((int)floor(interact->pos.z)) % 2;
	black = (int)0x002222;
	white = (int)0xffffff;
	if (bits_wise == 0)
		return (black);
	return (white);
}
