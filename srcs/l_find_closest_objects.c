/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_find_closest_objects.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 08:39:55 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 12:22:20 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	find_closest_object(t_scene *scene, t_ray_all ray, \
						t_interact *interact, void **object)
{
	interact->dist = INFINITY;
	if (scene->cylinder_id > 0)
		if (rollover_cylinders(scene, &ray, interact, object) == 1)
			scene->closest_object = 'c';
	if (scene->plane_id > 0)
		if (rollover_planes(scene, ray, interact, object) == 1)
			scene->closest_object = 'p';
	if (scene->sphere_id > 0)
		if (rollover_spheres(scene, ray, interact, object) == 1)
			scene->closest_object = 's';
	if (scene->square_id > 0)
		if (rollover_squares(&ray, scene, interact, object) == 1)
			scene->closest_object = 'q';
	if (scene->triangle_id > 0)
		if (rollover_triangles(scene, ray, interact, object) == 1)
			scene->closest_object = 't';
	return (0);
}
