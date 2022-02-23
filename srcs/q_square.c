/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_square.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:29:55 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 12:35:10 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rollover_squares(t_ray_all *ray, t_scene *scene, \
					t_interact *interact, void **object)
{
	int			yes;
	t_list		*squares;
	t_square	*square;

	yes = 0;
	squares = scene->squares;
	while (squares->next)
	{
		square = (t_square *)(squares->content);
		if (intersect_square(ray, square, interact) == 1)
		{
			yes = 1;
			*object = square;
			scene->global_id = square->global_id;
		}
		squares = squares->next;
	}
	return (yes);
}

int	intersect_square(t_ray_all *ray, t_square *square, \
					t_interact *interact)
{
	double		denom;
	double		res;
	t_triplet	interact_pos;

	denom = vect_product(square->normal, ray->dir);
	if (fabs(denom) > 1e-6)
	{
		res = vect_product(square->normal, \
			vect_substraction(square->position, ray->pos)) / denom;
		if (res >= -EPSILON && res < interact->dist)
		{
			interact_pos = vect_composition(ray->pos, \
				multiply_vector(ray->dir, res));
			interact_pos = vect_composition(interact_pos, \
				multiply_vector(square->normal, EPSILON));
			if (inside_sq_point(interact_pos, square) == 0)
				return (0);
			else
				return (set_interact_properties(res, ray, interact, square));
		}
	}
	return (0);
}

int	inside_sq_point(t_triplet hit_point, t_square *square)
{
	square->half_height = square->height / 2;
	if (fabs(hit_point.x - square->position.x) > square->half_height || \
		fabs(hit_point.y - square->position.y) > square->half_height || \
		fabs(hit_point.z - square->position.z) > square->half_height)
		return (0);
	return (1);
}

int	set_interact_properties(double x, t_ray_all *ray, \
							t_interact *interact, t_square *square)
{
	interact->pos = vect_composition(ray->pos, multiply_vector(ray->dir, x));
	interact->normal = square->normal;
	if (cos_a(ray->dir, interact->normal) > 0)
		interact->normal = multiply_vector(interact->normal, -1);
	interact->normal = nrmlz_vector(interact->normal);
	interact->dist = x;
	return (1);
}
