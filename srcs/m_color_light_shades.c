/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_color_light_shades.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:06:14 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 12:26:02 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"			

int	get_final_color(t_scene *scene, t_interact *interact)
{
	int		final_color;

	final_color = 0;
	interact->light_effect[0] = 0.0;
	interact->light_effect[1] = 0.0;
	interact->light_effect[2] = 0.0;
	add_coeff(interact, scene->amb_light_ratio, scene->amb_light_color);
	find_lights(scene, interact);
	final_color = color_x_light(interact->color, interact->light_effect);
	return (final_color);
}

void	find_lights(t_scene *scene, t_interact *interact)
{
	t_list		*lit_select;
	void		*obstacle;

	lit_select = scene->lights;
	while (lit_select->next != NULL)
	{
		obstacle = NULL;
		find_shades(scene, *(t_light *)(lit_select->content), \
					interact, &obstacle);
		lit_select = lit_select->next;
	}
}

int	find_shades(t_scene *scene, t_light light, t_interact *interact, \
					void **obstacle)
{
	t_ray_all	light_ray;
	t_triplet	light_dir;
	t_interact	active_interact;
	double		coeff;

	coeff = 0.0;
	light_dir = vect_substraction(light.position, interact->pos);
	light_ray = new_ray(interact->pos, nrmlz_vector(light_dir), INFINITY);
	find_closest_object(scene, light_ray, &active_interact, obstacle);
	if (active_interact.dist == INFINITY || \
		active_interact.dist >= vect_length(light_dir))
	{
		if (vect_product(interact->normal, light_dir) > 0)
		{
			coeff = light.ratio * cos_a(interact->normal, light_dir);
			add_coeff(interact, coeff, light.color);
			return (1);
		}
	}
	return (0);
}

void	add_coeff(t_interact *interact, double coef, int color)
{
	t_rgb	from_color;

	from_color = color_to_rgb(color);
	interact->light_effect[0] += coef * from_color.red / 255.0;
	interact->light_effect[1] += coef * from_color.blue / 255.0;
	interact->light_effect[2] += coef * from_color.green / 255.0;
}

int	color_x_light(int color, double light_effect[3])
{
	unsigned int	mask;
	t_rgb			new_color;
	int				result;

	mask = (255 << 16);
	new_color.red = light_effect[0] * ((color & mask) >> 16);
	if (new_color.red > 255)
		new_color.red = 255;
	mask >>= 8;
	new_color.green = light_effect[1] * ((color & mask) >> 8);
	if (new_color.green > 255)
		new_color.green = 255;
	mask >>= 8;
	new_color.blue = light_effect[2] * (color & mask);
	if (new_color.blue > 255)
		new_color.blue = 255;
	result = rgb_to_color(new_color);
	return (result);
}
