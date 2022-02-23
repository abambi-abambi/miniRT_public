/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_save_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:06:26 by abambi            #+#    #+#             */
/*   Updated: 2021/05/01 17:11:49 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	save_bmp_file(t_scene *scene, t_mlx mlx)
{
	int		fd;
	char	*time_stamp;
	char	*final_name;
	char	*tmp;

	time_stamp = ft_itoa(time(NULL));
	final_name = ft_strjoin("screenshot", time_stamp);
	tmp = final_name;
	final_name = ft_strjoin(final_name, ".bmp");
	free(tmp);
	free(time_stamp);
	printf("\n\tSaving image data into bmp-file: %s ... \n", final_name);
	fd = open(final_name, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0744);
	if (fd < 0)
		fatal_err1("error 2 while creating bmp-file", scene);
	free(final_name);
	create_file_header(fd, scene);
	create_image_header(fd, scene);
	save_buffer(fd, scene, mlx);
	close(fd);
	printf("Successfully saved!\n");
	exit(0);
}

void	create_file_header(int fd, t_scene *scene)
{
	int		file_header[3];
	int		file_size;
	int		offset_size;
	int		reserved_field;

	file_size = (int)(scene->res_w * scene->res_h * 4) + 54;
	offset_size = 54;
	reserved_field = 0;
	write (fd, "BM", 2);
	file_header[0] = file_size;
	file_header[1] = reserved_field;
	file_header[2] = offset_size;
	write(fd, (char *)file_header, 12);
}

void	create_image_header(int fd, t_scene *scene)
{
	int		image_header[10];
	int		image_header_size;
	int		i;

	image_header_size = 40;
	image_header[0] = image_header_size;
	image_header[1] = scene->res_w;
	image_header[2] = scene->res_h;
	image_header[3] = 1 + 24 * 256 * 256;
	i = 4;
	while (i <= 9)
		image_header[i++] = 0;
	write(fd, (char *)image_header, 40);
}

void	save_buffer(int fd, t_scene *scene, t_mlx mlx)
{
	int						i;
	int						j;
	int						padding_size;
	static unsigned char	padding[3];

	ft_memset(padding, 0, 3);
	padding_size = (4 - (scene->res_w * 3) % 4) % 4;
	i = scene->res_h;
	while (i-- > 0)
	{
		j = -1;
		while (++j < scene->res_w)
			write(fd, (void *)&mlx.cam->px_img[i * scene->res_w + j], 3);
		write(fd, padding, padding_size);
	}
}
