/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 08:42:41 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 13:46:05 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "defines.h"
# include "libft.h"
# include "mlx.h"
# include "objects.h"
# include "parsing.h"
# include "structs.h"
# include "vectors.h"

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

/*
**	General
*/

void		start_mlx(t_mlx *mlx, t_scene *scene);
void		mlx_utils(t_mlx mlx, t_scene *scene);
void		limit_max_screen_size(t_mlx *mlx, t_scene *scene);
int			keyboard_close(int keycode, t_mlx *mlx, t_scene *scene);
int			keyboard_cameras(int keycode, t_mlx *mlx, t_scene *scene);
void		go_to_render(t_mlx	mlx, t_scene *scene, int flag);
void		render(t_scene *scene, t_mlx mlx, int flag);
void		find_lights(t_scene *scene, t_interact *interact);
int			find_shades(t_scene *scene, t_light light, t_interact *interact, \
					void **obstacle);
int			close_program(t_mlx *mlx);

/*
**				Intersection functions
*/

int			set_interact_properties(double x, t_ray_all *ray, \
				t_interact *interact, t_square *square);

/*
**				Errors
*/

int			check_errors(int ac, char **av);
void		scene_err(char *message);
int			exit_window(t_mlx *mlx);
void		fatal_err1(char *message, t_scene *scene);
void		fatal_err2(char *message, t_scene *scene, t_mlx **mlx);
void		clean_scene_memory(t_scene *scene);
void		ft_free_cameras(t_mlx **mlx);

/*
**				Camera
*/

t_triplet	set_camera(t_scene *scene, t_mlx mlx);
t_triplet	set_camera_rotation(t_triplet res, t_mlx mlx);

/*
**				Colors
*/

int			get_color(t_scene *scene, void *object, t_interact *interact);
int			get_final_color(t_scene *scene, t_interact *interact);
void		add_coeff(t_interact *interact, double coef, int color);
int			color_x_light(int color, double light_effect[3]);
t_rgb		color_to_rgb(int color);
int			rgb_to_color(t_rgb rgb);
void		set_texture(int flag, t_interact *interact, int color);
int			checkerboard(t_interact *interact);

/*
**				Utils
*/

int			check_max_int(int num);
double		cos_a(t_triplet a, t_triplet b);
double		sqr(double x);
double		in_rad(double angle);

/*
**				Save bmp
*/

void		save_bmp_file(t_scene *scene, t_mlx mlx);
void		create_file_header(int fd, t_scene *scene);
void		create_image_header(int fd, t_scene *scene);
void		save_buffer(int fd, t_scene *scene, t_mlx mlx);

#endif
