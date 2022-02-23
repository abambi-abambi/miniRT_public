/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_check_args_errors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 08:39:55 by abambi            #+#    #+#             */
/*   Updated: 2021/05/01 15:16:13 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_errors(int ac, char **av)
{
	int		len;

	len = 0;
	if (ac < 2 || ac > 3)
		scene_err("wrong number of arguments! \n\n * Need at least 1 argument (name of scene) or \n ** 1-st plus \
2-nd argument: --save (for saving scene to bmp-file)\n\n");
	len = ft_strlen(av[1]);
	if (len <= 3 || (ft_strncmp(av[1] + len - 3, ".rt", 3)) \
		|| (len >= 4 && (ft_strncmp(av[1] + len - 4, "/.rt", 3)) == 0))
		scene_err("wrong file format! \n\n \
		* 1-st argument (file) should be a file (name) with .rt type\n\n");
	if (ac == 3 && ft_strncmp(av[2], "--save", 6) != 0)
		scene_err("wrong 2-nd argument for saving the scene. \n\n * Specify --save (the 2nd argument to save \
the scene)\n\n");
	return (1);
}
