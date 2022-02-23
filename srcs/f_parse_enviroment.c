/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_parse_enviroment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:52:59 by abambi            #+#    #+#             */
/*   Updated: 2021/05/01 15:44:46 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_resolution(t_scene *scene, char **str)
{
	if (scene->res_def == 1)
		fatal_err1("Resolution (R) can be declared only once\n", scene);
	scene->res_def = 1;
	skip_spaces_tabs(str);
	scene->res_w = atoi_rt(str);
	scene->res_h = atoi_rt(str);
	if (scene->res_w < 1 || scene->res_h < 1 || scene->res_w > INFINITY \
												|| scene->res_h > INFINITY)
		fatal_err1("Resolution is out of range: (1 - INFINITY). \
		Unable to build scene", scene);
	printf("Resolution:\twidth: %i;\theight: %i\n", scene->res_w, scene->res_h);
}

void	parse_ambient_light(t_scene *scene, char **str)
{
	if (scene->amb_light_def == 1)
		fatal_err1("Ambient lightning (A) can be declared only once\n", scene);
	scene->amb_light_def = 1;
	skip_spaces_tabs(str);
	scene->amb_light_ratio = atof_rt(str);
	if (scene->amb_light_ratio < 0 || scene->amb_light_ratio > 1)
		fatal_err1("Ambient lightning is out of range: \
		less than 0 or more than 1", scene);
	scene->amb_light_color = parse_rgb_color(str);
	printf("Ambient light:\tratio: %.1f;\tcolor: %X \n", \
		scene->amb_light_ratio, scene->amb_light_color);
	scene->amb_light_color *= scene->amb_light_ratio;
}

int	lstadd_cam_back(t_mlx *mlx, t_camera *camera, int index_old)
{
	if (mlx->cam)
	{
		while (mlx->cam->next)
			mlx->cam = mlx->cam->next;
		index_old = mlx->cam->idx;
		mlx->cam->next = camera;
	}
	else
		mlx->cam = camera;
	return (index_old);
}

void	parse_camera(t_scene *scene, char **str, t_mlx *mlx)
{
	t_camera	*camera;
	t_camera	*begin;
	int			index_old;

	begin = mlx->cam;
	index_old = 0;
	camera = malloc(sizeof(t_camera));
	if (!(camera))
		fatal_err1("Fail during malloc for camera", scene);
	camera->next = NULL;
	camera->idx = 1 + lstadd_cam_back(mlx, camera, index_old);
	scene->camera_id = scene->camera_id + 1;
	skip_spaces_tabs(str);
	camera->pos = parse_x_y_z(str);
	camera->dest = nrmlz_vector(parse_x_y_z(str));
	camera->fov = atoi_rt(str);
	if (camera->fov < 0 || camera->fov > 180)
		fatal_err2("wrong FOV is specified for camera\n", scene, &mlx);
	printf("Camera № %i: position: %.1f %.1f %.1f;\tFOV: %i\n", \
	scene->camera_id, camera->pos.x, camera->pos.y, camera->pos.z, camera->fov);
	if (begin != NULL)
		mlx->cam = begin;
	else
		mlx->cam = camera;
}

void	parse_light(t_scene *scene, char **str)
{
	t_light		*light;
	double		ratio;

	scene->light_id++;
	printf("Light spot № %i: ", scene->light_id);
	light = malloc(sizeof(*light));
	if (!(light))
		scene_err("Fail in malloc for light");
	skip_spaces_tabs(str);
	light->position = parse_x_y_z(str);
	ratio = atof_rt(str);
	if (ratio < 0 || ratio > 1)
	{
		printf("\nBrightness (ratio) = %f\n", ratio);
		scene_err("wrong brightness (ratio) is specified for light\n");
	}
	light->ratio = ratio;
	light->color = parse_rgb_color(str);
	ft_lstadd_front(&(scene->lights), ft_lstnew(light));
	printf("position: %.1f %.1f %.1f;\tbrightness: %.1f;\tcolor: %X\n", \
		light->position.x, light->position.y, light->position.z, ratio, \
			light->color);
}
