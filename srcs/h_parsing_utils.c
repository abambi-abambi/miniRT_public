/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_parsing_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 10:59:18 by abambi            #+#    #+#             */
/*   Updated: 2021/05/01 16:00:58 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	skip_spaces_tabs(char **str)
{
	while (**str == ' ' || **str == '\t')
		(*str)++;
	return (0);
}

int	atoi_rt(char **str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	if (**str == '-' && *((*str)++) != '\0')
		sign = -1;
	while (**str >= 48 && **str <= 57)
	{
		num = num * 10;
		num = num + (*((*str)++) - '0');
		if (check_max_int(num) == 1)
			break ;
	}
	skip_spaces_tabs(str);
	return (sign * num);
}

double	atof_rt(char **str)
{
	int		sign;
	int		inum;
	double	fnum;

	inum = 0;
	sign = 1;
	fnum = 0.0;
	if (**str == '-' && *((*str)++) != '\0')
		sign = -1;
	while (**str >= '0' && **str <= '9')
	{
		inum = inum * 10;
		inum = inum + (*((*str)++) - '0');
		if (check_max_int(inum) == 1)
			break ;
	}
	if (**str == '.')
		(*str)++;
	while (**str >= '0' && **str <= '9')
		fnum = fnum * 10 + (*((*str)++) - '0');
	while (fnum >= 1)
		fnum = fnum / 10.0;
	skip_spaces_tabs(str);
	return (sign * (fnum + inum));
}

int	parse_rgb_color(char **str)
{
	int	rgb[3];

	rgb[0] = 0;
	rgb[1] = 0;
	rgb[2] = 0;
	rgb[0] = atoi_rt(str);
	if (rgb[0] < 0 || rgb[0] > 255)
		scene_err("check RED color identification: correct range 0 - 255\n");
	if (**str != ',')
		scene_err("separpation character between color values \
			should be a comma: , \n");
	(*str)++;
	rgb[1] = atoi_rt(str);
	if (rgb[1] < 0 || rgb[1] > 255)
		scene_err("check GREEN color identification: correct range 0 - 255\n");
	if (**str != ',')
		scene_err("separation character between color values \
			should be a comma: , \n");
	(*str)++;
	rgb[2] = atoi_rt(str);
	if (rgb[2] < 0 || rgb[2] > 255)
		scene_err("check BLUE color identification: correct range 0 - 255\n");
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

t_triplet	parse_x_y_z(char **str)
{
	t_triplet	add;

	add.x = atof_rt(str);
	if (**str != ',')
		scene_err("separation character between position coordinates \
			should be a comma: , \n");
	(*str)++;
	add.y = atof_rt(str);
	if (**str != ',')
		scene_err("separation character between position coordinates \
			should be a comma: , \n");
	(*str)++;
	add.z = atof_rt(str);
	skip_spaces_tabs(str);
	return (add);
}
