/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 08:42:41 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 14:00:31 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

/*
**		Vectors
*/

double			distance(t_triplet a, t_triplet b);
t_triplet		multiply_vector(t_triplet vect, double x);
t_triplet		new_vector(double x, double y, double z);
t_ray_all		new_ray(t_triplet position, t_triplet direction, \
					double distance);
t_triplet		nrmlz_vector(t_triplet p);
t_triplet		vect_composition(const t_triplet a, t_triplet b);
t_triplet		vect_cross_product(t_triplet a, t_triplet b);
double			vect_length(t_triplet v);
double			vect_product(t_triplet a, t_triplet b);
t_triplet		vect_substraction(t_triplet a, t_triplet b);

#endif