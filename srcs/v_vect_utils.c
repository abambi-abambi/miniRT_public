/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_vect_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:06:14 by abambi            #+#    #+#             */
/*   Updated: 2021/05/01 17:07:04 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray_all	new_ray(t_triplet position, t_triplet direction, \
					double distance)
{
	t_ray_all	ray;

	ray.pos = position;
	ray.dir = direction;
	ray.dist = distance;
	return (ray);
}

t_triplet	new_vector(double x, double y, double z)
{
	t_triplet	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

t_triplet	nrmlz_vector(t_triplet p)
{
	t_triplet	result;
	double		len;

	len = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
	result.x = p.x / len;
	result.y = p.y / len;
	result.z = p.z / len;
	return (result);
}

double	vect_length(t_triplet v)
{
	double		len;

	len = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (len);
}
