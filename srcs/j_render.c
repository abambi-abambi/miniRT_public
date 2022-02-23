/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_render.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 08:39:55 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 12:14:27 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	go_to_render(t_mlx	mlx, t_scene *scene, int flag)
{
	if (scene->camera_id == 0)
	{
		printf("\n\tAttention! No camera(s) in scene...\n");
		return ;
	}
	while (mlx.cam != NULL)
	{
		render(scene, mlx, flag);
		mlx.cam = mlx.cam->next;
	}
}

void	render(t_scene *scene, t_mlx mlx, int flag)
{
	t_interact	interact;
	t_ray_all	ray_all;
	void		*object;

	(void)flag;
	scene->mlx_y = -1;
	while (++scene->mlx_y < scene->res_h)
	{
		scene->mlx_x = -1;
		while (++scene->mlx_x < scene->res_w)
		{
			object = NULL;
			interact.color = (int)0x202020;
			scene->closest_object = 0;
			ray_all = new_ray(mlx.cam->pos, set_camera(scene, mlx), INFINITY);
			find_closest_object(scene, ray_all, &interact, &object);
			if (object != NULL)
			{
				interact.color = get_color(scene, object, &interact);
				interact.color = get_final_color(scene, &interact);
			}
			mlx.cam->px_img[scene->mlx_y * scene->res_w + scene->mlx_x] \
				= interact.color;
		}
	}
}

int	get_color(t_scene *scene, void *object, t_interact *interact)
{
	char	type;

	type = scene->closest_object;
	if (type == 'c')
	{
		if (((t_cylinder *)object)->radius == 8)
			return (checkerboard(interact));
		else
			return (((t_cylinder *)object)->color);
	}
	if (type == 'p')
		return (((t_plane *)object)->color);
	if (type == 'q')
		return (((t_square *)object)->color);
	if (type == 's')
	{
		if (((t_sphere *)object)->radius == 20)
			return (checkerboard(interact));
		else
			return (((t_sphere *)object)->color);
	}
	if (type == 't')
		return (((t_triangle *)object)->color);
	return (1);
}
