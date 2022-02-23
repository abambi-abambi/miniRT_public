/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_cylinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:30:46 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 13:23:26 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rollover_cylinders(t_scene *scene, t_ray_all *ray, \
						t_interact *interact, void **object)
{
	t_list		*cylinders;
	t_cylinder	*cylinder;
	int			yes;

	yes = 0;
	cylinders = scene->cylinders;
	while (cylinders->next)
	{
		cylinder = (t_cylinder *)(cylinders->content);
		if (intersect_cylinder(ray, cylinder, interact) == 1)
		{
			yes = 1;
			*object = cylinder;
		}
		cylinders = cylinders->next;
	}
	return (yes);
}

int	solve_cyl(t_ray_all *ray, t_cylinder *cylinder, double *abc)
{
	t_triplet		shift;
	double			d1;
	double			dist;

	shift = vect_substraction(ray->pos, cylinder->pos);
	dist = vect_product(ray->dir, cylinder->dir);
	d1 = vect_product(shift, cylinder->dir);
	abc[0] = vect_product(ray->dir, ray->dir) - sqr(dist);
	abc[1] = 2 * (vect_product(ray->dir, shift) - dist * d1);
	abc[2] = vect_product(shift, shift) - sqr(d1) - sqr(cylinder->radius);
	return (1);
}

int	check_cyl_res(t_ray_all *ray, t_cylinder *cylinder, double *sq)
{
	t_triplet	prolongate;
	t_triplet	shift1;
	t_triplet	shift2;
	t_triplet	move;

	move = vect_composition(multiply_vector(cylinder->dir, \
		cylinder->height), cylinder->pos);
	prolongate = multiply_vector(ray->dir, sq[0]);
	shift1 = vect_substraction(vect_composition(ray->pos, prolongate), \
		cylinder->pos);
	shift2 = vect_substraction(move, vect_composition(ray->pos, \
		multiply_vector(ray->dir, sq[0])));
	if (vect_product(nrmlz_vector(shift1), cylinder->dir) >= EPSILON && \
		vect_product(nrmlz_vector(shift2), cylinder->dir) >= EPSILON && \
		sq[0] < INFINITY && sq[0] > EPSILON)
		return (1);
	return (0);
}

int	intersect_cylinder(t_ray_all *ray, t_cylinder *cylinder, \
						t_interact *interact)
{	
	double			abc[3];
	double			dist;	
	double			d2;
	double			sq[2];

	dist = INFINITY;
	solve_cyl(ray, cylinder, &abc[0]);
	d2 = sqr(abc[1]) - 4 * abc[0] * abc[2];
	if (d2 < EPSILON)
		return (0);
	sq[0] = (-abc[1] + sqrt(d2)) / (2 * abc[0]);
	sq[1] = (-abc[1] - sqrt(d2)) / (2 * abc[0]);
	if (check_cyl_res(ray, cylinder, &sq[0]) == 1)
		dist = sq[0];
	if (check_cyl_res(ray, cylinder, &sq[1]) == 1)
		dist = sq[1];
	if (dist == sq[1] || dist == sq[0])
	{
		if (dist > 0 && dist < interact->dist)
		{
			set_cyl_interact_point(cylinder, ray, interact, dist);
			return (1);
		}
	}
	return (0);
}

void	set_cyl_interact_point(t_cylinder *cylinder, \
	t_ray_all *ray, t_interact *interact, double dist)
{
	t_triplet	shift;
	double		prolongate;
	double		res;

	interact->dist = dist;
	interact->pos = vect_composition(ray->pos, \
				multiply_vector(ray->dir, interact->dist));
	shift = vect_substraction(ray->pos, cylinder->pos);
	prolongate = vect_product(ray->dir, cylinder->dir) * interact->dist;
	res = prolongate + vect_product(shift, cylinder->dir);
	interact->normal = vect_substraction(vect_substraction(\
		interact->pos, cylinder->pos), multiply_vector(cylinder->dir, res));
	if (cos_a(ray->dir, interact->normal) > 0)
		interact->normal = multiply_vector(interact->normal, -1);
	interact->normal = nrmlz_vector(interact->normal);
}
