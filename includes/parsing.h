/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 08:42:41 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 14:01:46 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/*
**			 	Parsing
*/

int			get_next_line_a(char **av, char **line);
int			get_next_line_b(int fd, char **line);
void		parse_scene(t_scene	*scene, char *str, t_mlx *mlx);
void		*init_scene(t_scene *scene);
void		parse_resolution(t_scene *scene, char **str);
void		parse_ambient_light(t_scene *scene, char **str);
void		parse_camera(t_scene *scene, char **str, t_mlx *mlx);
void		parse_light(t_scene *scene, char **str);
void		parse_objects(t_scene *scene, char **str_p);
void		parse_cylinder(t_scene *scene, char **str);
void		parse_plane(t_scene *scene, char **str);
void		parse_sphere(t_scene *scene, char **str);
void		parse_square(t_scene *scene, char **str);
void		parse_triangle(t_scene *scene, char **str);

/*
**				Parsing 2
*/

int			atoi_rt(char **str);
double		atof_rt(char **str);
int			skip_spaces_tabs(char **str);
t_triplet	parse_x_y_z(char **str);
int			parse_rgb_color(char **str);

#endif