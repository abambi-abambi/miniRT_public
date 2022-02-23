/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_parse_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 08:39:55 by abambi            #+#    #+#             */
/*   Updated: 2021/05/01 15:25:09 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_scene(t_scene	*scene, char *str, t_mlx *mlx)
{
	printf("Parsing data...\n");
	mlx->cam = NULL;
	while (*str)
	{
		if (*str == '#')
			while (*str != '\n' && *str != '\0')
				str++;
		else
		{
			if (*str == 'R' && *(str++))
				parse_resolution(scene, &str);
			else if (*str == 'A' && *(str++))
				parse_ambient_light(scene, &str);
			else if (*str == 'c' && (*(str + 1) == ' ' \
			 || *(str + 1) == '\t') && *(str++))
				parse_camera(scene, &str, mlx);
			else if (*str == 'l' && *(str - 1) != 'p' \
			&& (*(str + 1) == ' ' || *(str + 1) == '\t') && *(str++))
				parse_light(scene, &str);
			parse_objects(scene, &str);
		}
		str++;
	}
	if (scene->res_def == 0)
		scene_err("resolution (R) is not specified\n");
}

void	parse_objects(t_scene *scene, char **str_p)
{
	char	*str;

	str = *str_p;
	if (*str == 'c' && *(str + 1) == 'y' && *(str++) && *(str++))
		parse_cylinder(scene, &str);
	else if (*str == 'p' && *(str + 1) == 'l' && *(str++) && *(str++))
		parse_plane(scene, &str);
	else if (*str == 's' && *(str + 1) == 'p' && *(str++) && *(str++))
		parse_sphere(scene, &str);
	else if (*str == 's' && *(str + 1) == 'q' && *(str++) && *(str++))
		parse_square(scene, &str);
	else if (*str == 't' && *(str + 1) == 'r' && *(str++) && *(str++))
		parse_triangle(scene, &str);
	*str_p = str;
}
