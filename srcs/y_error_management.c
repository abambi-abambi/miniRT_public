/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   y_error_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:05:30 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 14:25:28 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fatal_err1(char *message, t_scene *scene)
{
	clean_scene_memory(scene);
	perror(message);
	exit(EXIT_FAILURE);
}

void	fatal_err2(char *message, t_scene *scene, t_mlx **mlx)
{
	clean_scene_memory(scene);
	if (mlx)
		if ((*mlx)->cam->idx)
			ft_free_cameras(mlx);
	if (mlx)
		mlx_destroy_window((*mlx)->mlx, (*mlx)->window);
	if (mlx)
		free(mlx);
	perror(message);
	exit(EXIT_FAILURE);
}

void	scene_err(char *message)
{
	printf("Error: %s", message);
	exit(EXIT_FAILURE);
}

void	clean_scene_memory(t_scene *scene)
{
	if (ft_lstsize(scene->lights))
		ft_lstclear(&(scene->lights), free);
	if (ft_lstsize(scene->spheres))
		ft_lstclear(&(scene->spheres), free);
	if (ft_lstsize(scene->planes))
		ft_lstclear(&(scene->planes), free);
	if (ft_lstsize(scene->triangles))
		ft_lstclear(&(scene->triangles), free);
	if (ft_lstsize(scene->squares))
		ft_lstclear(&(scene->squares), free);
	if (ft_lstsize(scene->cylinders))
		ft_lstclear(&(scene->cylinders), free);
	if (scene)
		free(scene);
}

void	ft_free_cameras(t_mlx **mlx)
{
	t_camera	*camera;
	t_camera	*next;

	camera = (*mlx)->cam;
	while (camera)
	{
		next = camera->next;
		free(camera);
		camera = next;
	}
}
