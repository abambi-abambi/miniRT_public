/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 08:42:41 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 13:59:21 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_triplet
{
	double			x;
	double			y;
	double			z;
}					t_triplet;

typedef struct s_rgb
{
	int				red;
	int				green;
	int				blue;
}					t_rgb;

typedef struct s_camera
{
	t_triplet		pos;
	t_triplet		dest;
	int				fov;
	int				init;
	int				idx;
	void			*img_ptr;
	int				*px_img;
	int				bpp;
	int				size_line;
	int				endian;
	struct s_camera	*next;
}					t_camera;

typedef struct s_mlx
{
	int				x;
	int				y;
	int				camera_mlx;
	t_camera		*cam;
	t_camera		*begin;
	void			*mlx;
	void			*window;
}					t_mlx;

typedef struct s_light
{
	t_triplet		position;
	double			ratio;
	int				color;
}					t_light;

typedef struct s_sphere
{
	t_triplet		center;
	double			radius;
	int				color;
	int				inside;
	int				global_id;
}					t_sphere;

typedef struct s_plane
{
	t_triplet		position;
	t_triplet		normal;
	int				color;
	int				global_id;
}					t_plane;

typedef struct s_triangle
{
	t_triplet		p1;
	t_triplet		p2;
	t_triplet		p3;
	t_triplet		normal;
	int				color;
	int				global_id;
}					t_triangle;

typedef struct s_square
{
	t_triplet		position;
	t_triplet		normal;
	double			height;
	double			half_height;
	int				color;
	int				global_id;
}					t_square;

typedef struct s_cylinder
{
	t_triplet		pos;
	t_triplet		pos2;
	t_triplet		dir;
	t_triplet		normal;
	double			radius;
	double			height;
	int				color;
	double			dist1;
	double			dist2;
	int				global_id;
}					t_cylinder;

typedef struct s_ray_all
{
	t_triplet		pos;
	t_triplet		dir;
	double			dist;
}					t_ray_all;

typedef struct s_interact
{
	double			dist;
	int				color;
	t_triplet		pos;
	t_triplet		normal;
	double			light_effect[3];
}					t_interact;

typedef struct s_scene
{
	char			res_def;
	int				res_w;
	int				res_h;
	char			amb_light_def;
	double			amb_light_ratio;
	int				amb_light_color;
	int				camera_id;
	int				light_id;
	t_list			*lights;
	int				sphere_id;
	t_list			*spheres;
	int				plane_id;
	t_list			*planes;
	int				square_id;
	t_list			*squares;
	int				cylinder_id;
	t_list			*cylinders;
	int				triangle_id;
	t_list			*triangles;
	int				mlx_x;
	int				mlx_y;
	char			closest_object;
	int				global_id;
}					t_scene;

#endif