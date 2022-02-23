/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 08:42:41 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 14:38:23 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "structs.h"

/*
**	General
*/

int			find_closest_object(t_scene *scene, t_ray_all ray, \
				t_interact *interact, void **object);

/*
**	Sphere
*/

double		rollover_spheres(t_scene *scene, t_ray_all ray, \
				t_interact *interact, void **object);
double		sphere_intersect(t_sphere *sphere, t_ray_all ray, \
				t_interact *interact);
double		check_sp_diskr(double *dist, t_sphere *sphere, \
				t_ray_all ray, t_interact *interact);
void		change_sph_normal(t_ray_all ray, t_interact *interact, \
				t_sphere *sphere);

/*
**	Plane
*/

double		rollover_planes(t_scene *scene, t_ray_all ray, \
				t_interact *interact, void **object);
double		intersect_plane(t_ray_all ray, t_plane plane, t_interact *interact);
double		solve_plane(t_triplet ray_pos, t_triplet ray_dir, \
				t_triplet plane_pos, t_triplet plane_nv);

/*
**	Triangle
*/

double		rollover_triangles(t_scene *scene, t_ray_all ray, \
				t_interact *interact, void **object);
int			intersect_triangle(t_ray_all *ray, t_triangle *triangle, \
				t_interact *interact);

/*
**	Square
*/

int			rollover_squares(t_ray_all *ray, t_scene *scene, \
				t_interact *interact, void **object);
int			intersect_square(t_ray_all *ray, t_square *square, \
				t_interact *interact);
int			inside_sq_point(t_triplet hit_point, t_square *square);

/*
**	Cylinder
*/

int			rollover_cylinders(t_scene *scene, t_ray_all *ray, \
				t_interact *interact, void **object);
int			intersect_cylinder(t_ray_all *ray, t_cylinder *cylinder, \
				t_interact *interact);
void		set_cyl_interact_point(t_cylinder *cylinder, \
				t_ray_all *ray, t_interact *interact, double dist);

#endif