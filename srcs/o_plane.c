/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_plane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:29:55 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 12:31:11 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	rollover_planes(t_scene *scene, t_ray_all ray, \
						t_interact *interact, void **object)
{
	int			yes;
	t_list		*planes;
	t_plane		*plane;

	yes = 0;
	planes = scene->planes;
	while (planes->next)
	{
		plane = (t_plane *)(planes->content);
		if (intersect_plane(ray, *plane, interact) == 1)
		{
			*object = plane;
			scene->global_id = plane->global_id;
			yes = 1;
		}
		planes = planes->next;
	}
	return (yes);
}

double	intersect_plane(t_ray_all ray, t_plane plane, t_interact *interact)
{
	double	x;
	double	denom;
	double	res;

	denom = plane.normal.x * ray.dir.x
		+ plane.normal.y * ray.dir.y
		+ plane.normal.z * ray.dir.z;
	if (fabs(denom) < 1e-6)
		return (0);
	x = plane.normal.x * (plane.position.x - ray.pos.x)
		+ plane.normal.y * (plane.position.y - ray.pos.y)
		+ plane.normal.z * (plane.position.z - ray.pos.z);
	res = x / denom;
	if (res > EPSILON && res < interact->dist)
	{
		interact->normal = plane.normal;
		if (cos_a(ray.dir, interact->normal) > 0)
			interact->normal = multiply_vector(interact->normal, -1);
		interact->normal = nrmlz_vector(interact->normal);
		interact->pos = vect_composition(ray.pos, \
						multiply_vector(ray.dir, res));
		interact->dist = res;
		return (1);
	}
	return (0);
}
