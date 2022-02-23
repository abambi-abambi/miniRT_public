/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_mlx_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:11:12 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 14:36:29 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	start_mlx(t_mlx *mlx, t_scene *scene)
{
	t_camera	*cam_begin;

	mlx->mlx = mlx_init();
	limit_max_screen_size(mlx, scene);
	cam_begin = mlx->cam;
	mlx->begin = mlx->cam;
	while (mlx->cam)
	{
		mlx->cam->img_ptr = mlx_new_image(mlx->mlx, scene->res_w, scene->res_h);
		mlx->cam->px_img = (int *)mlx_get_data_addr(mlx->cam->img_ptr, \
			&mlx->cam->bpp, &mlx->cam->size_line, &mlx->cam->endian);
		mlx->cam = mlx->cam->next;
	}
	mlx->cam = cam_begin;
}

void	limit_max_screen_size(t_mlx *mlx, t_scene *scene)
{
	int			screen_res_x;
	int			screen_res_y;

	if (SYSTEM_NAME == 1)
	{
		mlx_get_screen_size(mlx->mlx, &screen_res_x, &screen_res_y);
		if (scene->res_w > screen_res_x)
			scene->res_w = screen_res_x;
		if (scene->res_h > screen_res_y)
			scene->res_h = screen_res_y;
	}
	else
	{
		if (scene->res_w > 1280)
			scene->res_w = 1280;
		if (scene->res_h > 1024)
			scene->res_h = 1024;
	}
}

void	mlx_utils(t_mlx mlx, t_scene *scene)
{
	mlx.window = mlx_new_window(mlx.mlx, scene->res_w, scene->res_h, "miniRT");
	mlx_hook(mlx.window, 33, 0L, close_program, &mlx);
	mlx_hook(mlx.window, 2, 1L << 0, keyboard_close, &mlx);
	if (scene->camera_id != 0)
	{
		mlx_hook(mlx.window, 2, 1L << 0, keyboard_cameras, &mlx);
		mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.cam->img_ptr, 0, 0);
		mlx_string_put(mlx.mlx, mlx.window, (scene->res_h / 5), \
			(scene->res_w / 5), 0x00AAFF, "Hello, user!");
	}
	mlx_loop(mlx.mlx);
}

int	close_program(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit(0);
}

int	keyboard_close(int keycode, t_mlx *mlx, t_scene *scene)
{
	(void)scene;
	if (keycode == 65307)
		close_program(mlx);
	return (0);
}
