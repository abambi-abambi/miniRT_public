/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_vector_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:25:21 by abambi            #+#    #+#             */
/*   Updated: 2021/05/01 17:09:26 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_triplet	vect_composition(const t_triplet a, t_triplet b)
{
	t_triplet	result;

	result = new_vector(a.x + b.x, a.y + b.y, a.z + b.z);
	return (result);
}

t_triplet	vect_substraction(t_triplet a, t_triplet b)
{
	t_triplet	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return (result);
}

t_triplet	multiply_vector(t_triplet vect, double x)
{
	t_triplet	vector;

	vector = new_vector(vect.x * x, vect.y * x, vect.z * x);
	return (vector);
}

double	vect_product(t_triplet a, t_triplet b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_triplet	vect_cross_product(t_triplet a, t_triplet b)
{
	t_triplet	res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	return (res);
}
