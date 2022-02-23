/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_init_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 08:39:55 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 11:38:19 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*init_scene(t_scene *scene)
{
	scene->res_def = 0;
	scene->res_w = 0;
	scene->res_h = 0;
	scene->amb_light_def = 0;
	scene->amb_light_ratio = 0;
	scene->amb_light_color = 0;
	scene->camera_id = 0;
	scene->light_id = 0;
	scene->lights = ft_lstnew(NULL);
	scene->sphere_id = 0;
	scene->spheres = ft_lstnew(NULL);
	scene->plane_id = 0;
	scene->planes = ft_lstnew(NULL);
	scene->triangle_id = 0;
	scene->triangles = ft_lstnew(NULL);
	scene->square_id = 0;
	scene->squares = ft_lstnew(NULL);
	scene->cylinder_id = 0;
	scene->cylinders = ft_lstnew(NULL);
	scene->global_id = 0;
	return (scene);
}
