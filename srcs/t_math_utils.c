/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_math_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi     <abambi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:17:42 by abambi            #+#    #+#             */
/*   Updated: 2021/03/30 18:17:43 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	sqr(double x)
{
	return (x * x);
}

double	distance(t_triplet a, t_triplet b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2)));
}

double	in_rad(double angle)
{
	return (angle * M_PI * 0.5);
}

double	cos_a(t_triplet a, t_triplet b)
{
	double	result;

	result = vect_product(a, b) / (vect_length(a) * vect_length(b));
	return (result);
}

int	check_max_int(int num)
{
	if (num >= 30000)
	{
		printf("\n\tAttention: too big numbers are set to \
appropriate max for this program\n\n");
		num = 30000;
		return (1);
	}
	return (0);
}
