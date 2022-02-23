/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:08:58 by abambi            #+#    #+#             */
/*   Updated: 2021/05/07 13:44:08 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_H
# define MLX_H

void	*mlx_init(void);
void	*mlx_new_window(void *mlx_ptr, int width, int height, \
			char *title);
void	*mlx_new_image(void *mlx_ptr, int width, int height);
int		*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
			int *size_line, int *endian);
int		mlx_hook(void *mlx, int x_event, int x_mask, \
			int (*funct)(), void *param);
int		mlx_loop(void *mlx_ptr);
int		mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int		mlx_clear_window(void *mlx_ptr, void *win_ptr);
int		mlx_get_screen_size(void *mlx, int *screen_res_x, int *screen_res_y);
int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr,
			void *img_ptr, int x, int y);
int		mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y,
			int color, char *string);
int		mlx_destroy_window(void *mlx_ptr, void *win_ptr);

#endif
