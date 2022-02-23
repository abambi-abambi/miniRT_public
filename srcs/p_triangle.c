/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_triangle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:29:55 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 12:33:39 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	rollover_triangles(t_scene *scene, t_ray_all ray, \
							t_interact *interact, void **object)
{
	int			yes;
	t_list		*triangles;
	t_triangle	*triangle;

	yes = 0;
	triangles = scene->triangles;
	while (triangles->next)
	{
		triangle = (t_triangle *)(triangles->content);
		if (intersect_triangle(&ray, triangle, interact) == 1)
		{
			*object = triangle;
			scene->global_id = triangle->global_id;
			yes = 1;
		}
		triangles = triangles->next;
	}
	return (yes);
}

double	solve_plane(t_triplet ray_pos, t_triplet ray_dir, \
				t_triplet plane_pos, t_triplet plane_nv)
{
	double		res;
	double		denom;
	t_triplet	between;

	denom = vect_product(plane_nv, ray_dir);
	if (denom == 0)
		return (-1);
	between = vect_substraction(plane_pos, ray_pos);
	res = vect_product(plane_nv, between) / denom;
	if (res <= 0)
		return (-1);
	return (res);
}

int	outside_point(t_triplet p1, t_triplet p2, t_triplet p3, t_triplet ip)
{
	t_triplet	v1;
	t_triplet	v2;
	t_triplet	vp;
	t_triplet	arg1;
	t_triplet	arg2;

	v1 = vect_substraction(p2, p1);
	v2 = vect_substraction(p3, p1);
	vp = vect_substraction(ip, p1);
	arg1 = vect_cross_product(v1, v2);
	arg2 = vect_cross_product(v1, vp);
	if (cos_a(arg1, arg2) < 0)
		return (1);
	return (0);
}

int	intersect_triangle(t_ray_all *ray, t_triangle *triangle, \
						t_interact *interact)
{
	double		interact_dist;
	t_triplet	interact_pos;

	triangle->normal = vect_cross_product(\
		vect_substraction(triangle->p3, triangle->p1), \
		vect_substraction(triangle->p2, triangle->p1));
	triangle->normal = nrmlz_vector(triangle->normal);
	interact_dist = solve_plane(ray->pos, ray->dir, \
								triangle->p1, triangle->normal);
	interact_pos = vect_composition(ray->pos, \
									multiply_vector(ray->dir, interact_dist));
	if ((outside_point(triangle->p1, triangle->p2, triangle->p3, interact_pos)) || \
		(outside_point(triangle->p2, triangle->p3, triangle->p1, interact_pos)) || \
		(outside_point(triangle->p3, triangle->p1, triangle->p2, interact_pos)))
		return (0);
	if (interact_dist > EPSILON && interact_dist < interact->dist)
	{
		if (cos_a(ray->dir, triangle->normal) > 0)
			interact->normal = multiply_vector(triangle->normal, -1);
		interact->normal = nrmlz_vector(interact->normal);
		interact->pos = interact_pos;
		interact->dist = interact_dist;
		return (1);
	}
	return (0);
}
