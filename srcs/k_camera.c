/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_camera.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 08:39:55 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 12:20:29 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_triplet	set_camera(t_scene *scene, t_mlx mlx)
{
	double		img_asp_ratio;
	double		correct_fov;
	t_triplet	res;

	img_asp_ratio = (double)(scene->res_w) / (double)(scene->res_h);
	correct_fov = tan((mlx.cam->fov * M_PI / 180) / 2);
	res.x = \
		((2 * ((scene->mlx_x + 0.5) / scene->res_w)) - 1) * \
		img_asp_ratio * correct_fov;
	res.x = res.x * (-1);
	res.y = (1 - (2 * ((scene->mlx_y + 0.5) / scene->res_h))) * correct_fov;
	res.z = 1;
	res = nrmlz_vector(res);
	res = set_camera_rotation(res, mlx);
	return (res);
}

t_triplet	set_camera_rotation(t_triplet res, t_mlx mlx)
{
	t_triplet	raw_product;
	t_triplet	rotate;
	t_triplet	vx;
	t_triplet	vy;
	t_triplet	vz;

	raw_product = new_vector(0, 1, 0);
	vz = nrmlz_vector(mlx.cam->dest);
	vz = mlx.cam->dest;
	if (mlx.cam->dest.y == 1)
		vx = new_vector(1, 0, 0);
	else if (mlx.cam->dest.y == -1)
		vx = new_vector(-1, 0, 0);
	else
		vx = vect_cross_product(raw_product, vz);
	vx = nrmlz_vector(vx);
	vy = vect_cross_product(vz, vx);
	vy = nrmlz_vector(vect_cross_product(vz, vx));
	rotate.x = res.x * vx.x + res.y \
		* vy.x + res.z * vz.x;
	rotate.y = res.x * vx.y + res.y \
		* vy.y + res.z * vz.y;
	rotate.z = res.x * vx.z + res.y \
		* vy.z + res.z * vz.z;
	return (rotate);
}

int	keyboard_cameras(int keycode, t_mlx *mlx, t_scene *scene)
{
	(void)scene;
	if (keycode == 65307)
		close_program(mlx);
	if (keycode != 32)
		return (0);
	if (mlx->cam->next)
	{
		mlx->cam = mlx->cam->next;
		mlx_put_image_to_window(\
			mlx->mlx, mlx->window, mlx->cam->img_ptr, 0, 0);
	}
	else
	{
		mlx->cam = mlx->begin;
		mlx_put_image_to_window(\
		mlx->mlx, mlx->window, mlx->cam->img_ptr, 0, 0);
	}
	return (1);
}
