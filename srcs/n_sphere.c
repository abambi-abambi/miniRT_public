/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_sphere.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:18:19 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 12:30:03 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	rollover_spheres(t_scene *scene, t_ray_all ray, \
						t_interact *interact, void **object)
{
	int			yes;
	t_list		*spheres;
	t_sphere	*sphere;

	yes = 0;
	spheres = scene->spheres;
	while (spheres->next)
	{
		sphere = (t_sphere *)(spheres->content);
		if (sphere_intersect(sphere, ray, interact) == 1)
		{
			yes = 1;
			*object = sphere;
			scene->global_id = sphere->global_id;
		}
		spheres = spheres->next;
	}
	return (yes);
}

void	calculate_abc(double *abc, t_sphere *sphere, t_ray_all ray)
{
	t_triplet	c_sp_dist;

	abc[0] = vect_product(ray.dir, ray.dir);
	c_sp_dist = vect_substraction(ray.pos, sphere->center);
	abc[1] = 2 * (vect_product(c_sp_dist, ray.dir));
	abc[2] = vect_product(c_sp_dist, c_sp_dist) - sqr(sphere->radius);
}

double	sphere_intersect(t_sphere *sphere, t_ray_all ray, t_interact *interact)
{
	double		abc[3];
	float		discr;
	double		dist[2];

	calculate_abc(abc, sphere, ray);
	discr = sqr(abc[1]) - 4 * abc[0] * abc[2];
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		dist[0] = -abc[1] / (2 * abc[0]);
		dist[1] = dist[0];
	}
	else
	{
		dist[0] = (-abc[1] - sqrt(discr)) / (2 * abc[0]);
		if (dist[0] < 0)
			dist[0] = (-abc[1] + sqrt(discr)) / (2 * abc[0]);
	}
	return (check_sp_diskr(dist, sphere, ray, interact));
}

double	check_sp_diskr(double *dist, t_sphere *sphere, t_ray_all ray, \
					t_interact *interact)
{
	if (dist[0] > -EPSILON && dist[0] < interact->dist)
	{
		interact->dist = dist[0];
		interact->pos = vect_composition(ray.pos, \
			multiply_vector(ray.dir, dist[0]));
		interact->normal = vect_substraction(interact->pos, sphere->center);
		interact->normal = nrmlz_vector(interact->normal);
		interact->pos = vect_composition(interact->pos, \
			multiply_vector(interact->normal, 0.001));
		change_sph_normal(ray, interact, sphere);
		return (1);
	}
	return (0);
}

void	change_sph_normal(t_ray_all ray, t_interact *interact, t_sphere *sphere)
{
	if (cos_a(ray.dir, interact->normal) > 0 && \
		distance(interact->pos, sphere->center) > sphere->radius)
		interact->normal = multiply_vector(interact->normal, -1);
}
