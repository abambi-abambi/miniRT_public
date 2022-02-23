/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 08:39:55 by abambi            #+#    #+#             */
/*   Updated: 2021/04/01 15:05:47 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_scene	*scene;
	t_mlx	mlx;
	char	*line;

	printf("Checking input arg's errors...\n");
	check_errors(ac, av);
	printf("Opening input file...\n");
	get_next_line_a(av, &line);
	scene = malloc(sizeof(*scene));
	if (!(scene))
		scene_err("Fail of malloc for t_scene");
	if (!(init_scene(scene)))
		scene_err("Fail to init() t_scene");
	parse_scene(scene, line, &mlx);
	free(line);
	start_mlx(&mlx, scene);
	go_to_render(mlx, scene, 0);
	if (ac == 3)
		save_bmp_file(scene, mlx);
	mlx_utils(mlx, scene);
	return (0);
}
