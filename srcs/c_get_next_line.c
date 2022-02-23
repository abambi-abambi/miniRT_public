/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_get_next_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:39:55 by abambi            #+#    #+#             */
/*   Updated: 2021/05/01 15:19:36 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_next_line_a(char **av, char **line)
{
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		scene_err("Error during opening the input file");
	*line = malloc(1 * sizeof(char));
	if (!(*line))
		return (-1);
	**line = '\0';
	get_next_line_b(fd, line);
	return (1);
}

int	get_next_line_b(int fd, char **line)
{
	char	*tmp;
	char	buf[2];

	while (read(fd, buf, 1) == 1)
	{
		buf[1] = '\0';
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		if (!(*line))
		{
			free(tmp);
			tmp = NULL;
			scene_err("Error while reading input file");
		}
		free(tmp);
		tmp = NULL;
	}
	close(fd);
	return (1);
}
