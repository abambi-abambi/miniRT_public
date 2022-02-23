/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_color_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:11:12 by abambi            #+#    #+#             */
/*   Updated: 2021/05/01 17:07:53 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	correct_limits(t_rgb a)
{
	if (a.red > 255)
		a.red = 255;
	if (a.green > 255)
		a.green = 255;
	if (a.blue > 255)
		a.blue = 255;
	return (a);
}

t_rgb	color_to_rgb(int color)
{
	t_rgb	res;
	char	r;
	char	g;
	char	b;

	if (color > 2147483647)
		color = 2147483647;
	r = *((char *)&color + 2);
	res.red = (int)r + 256;
	g = *((char *)&color + 1);
	res.green = (int)g + 256;
	b = *((char *)&color + 0);
	res.blue = (int)b + 256;
	return (res);
}

int	rgb_to_color(t_rgb rgb)
{
	rgb = correct_limits(rgb);
	return (rgb.red << 16 | rgb.green << 8 | rgb.blue);
}
