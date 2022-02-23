/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_parse_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:49:05 by abambi            #+#    #+#             */
/*   Updated: 2021/05/01 15:50:36 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_cylinder(t_scene *scene, char **str)
{
	t_cylinder	*cyl;

	cyl = malloc(sizeof(*cyl));
	if (!(cyl))
		fatal_err1("Fail in malloc for cylinder object", scene);
	scene->cylinder_id++;
	cyl->global_id = ++scene->global_id;
	printf("Cylinder № %i: ", scene->cylinder_id);
	skip_spaces_tabs(str);
	cyl->pos = parse_x_y_z(str);
	cyl->dir = nrmlz_vector(parse_x_y_z(str));
	cyl->radius = atof_rt(str) / 2.0;
	cyl->height = atof_rt(str);
	cyl->color = parse_rgb_color(str);
	ft_lstadd_front(&(scene->cylinders), ft_lstnew(cyl));
	printf("position_new: p1 %.1f %.1f %.1f; dir: %.1f %.1f %.1f; \
radius %.1f; height %.1f; color: %X\n", \
		cyl->pos.x, cyl->pos.y, cyl->pos.z, \
	cyl->dir.x, cyl->dir.y, cyl->dir.z, \
	cyl->radius, cyl->height, cyl->color);
}

void	parse_plane(t_scene *scene, char **str)
{
	t_plane		*plane;

	plane = malloc(sizeof(*plane));
	if (!(plane))
		fatal_err1("Fail in malloc for plane object", scene);
	plane->global_id = ++scene->global_id;
	scene->plane_id++;
	printf("Plane № %i: ", scene->plane_id);
	skip_spaces_tabs(str);
	plane->position = parse_x_y_z(str);
	plane->normal = nrmlz_vector(parse_x_y_z(str));
	plane->color = parse_rgb_color(str);
	ft_lstadd_front(&(scene->planes), ft_lstnew(plane));
	printf("position: %.1f %.1f %.1f;\tnormal: %.1f %.1f %.1f;\tcolor: %X\n", \
		plane->position.x, plane->position.y, plane->position.z, \
			plane->normal.x, plane->normal.y, plane->normal.z, plane->color);
	printf("<- check color\n");
}

void	parse_sphere(t_scene *scene, char **str)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(*sphere));
	if (!(sphere))
		fatal_err1("Fail in malloc for sphere object", scene);
	sphere->global_id = ++scene->global_id;
	scene->sphere_id++;
	printf("Sphere № %i: ", scene->sphere_id);
	skip_spaces_tabs(str);
	sphere->center = parse_x_y_z(str);
	sphere->radius = atof_rt(str) / 2.0;
	sphere->color = parse_rgb_color(str);
	ft_lstadd_front(&(scene->spheres), ft_lstnew(sphere));
	printf("position: %.1f %.1f %.1f;\tdiameter: %.1f;\tcolor: %X\n", \
		sphere->center.x, sphere->center.y, sphere->center.z, \
		sphere->radius * 2, sphere->color);
}

void	parse_square(t_scene *scene, char **str)
{
	t_square	*square;

	square = malloc(sizeof(*square));
	if (!(square))
		fatal_err1("Fail of malloc for square object", scene);
	square->global_id = ++scene->global_id;
	scene->square_id++;
	printf("Square № %i: ", scene->square_id);
	skip_spaces_tabs(str);
	square->position = parse_x_y_z(str);
	square->normal = nrmlz_vector(parse_x_y_z(str));
	square->height = atof_rt(str);
	square->color = parse_rgb_color(str);
	ft_lstadd_front(&(scene->squares), ft_lstnew(square));
	printf("position: %.1f %.1f %.1f; normal: %.1f %.1f %.1f; \
		height %.1f; color: %X\n", \
		square->position.x, square->position.y, square->position.z, \
		square->normal.x, square->normal.y, square->normal.z, \
		square->height, square->color);
}

void	parse_triangle(t_scene *scene, char **str)
{
	t_triangle	*triangle;

	triangle = malloc(sizeof(*triangle));
	if (!(triangle))
		fatal_err1("Fail in malloc for triangle object", scene);
	triangle->global_id = ++scene->global_id;
	scene->triangle_id++;
	printf("Triangle № %i: ", scene->triangle_id);
	skip_spaces_tabs(str);
	triangle->p1 = parse_x_y_z(str);
	triangle->p2 = parse_x_y_z(str);
	triangle->p3 = parse_x_y_z(str);
	triangle->color = parse_rgb_color(str);
	ft_lstadd_front(&(scene->triangles), ft_lstnew(triangle));
	printf("position: p1 %.1f %.1f %.1f; p2: %.1f %.1f %.1f; \
		p3 %.1f %.1f %.1f; color: %X\n", \
		triangle->p1.x, triangle->p1.y, triangle->p1.z, \
		triangle->p2.x, triangle->p2.y, triangle->p2.z, \
		triangle->p3.x, triangle->p3.y, triangle->p3.z, triangle->color);
}
