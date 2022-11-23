/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:16:54 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/23 17:53:57 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// void	draw_line(t_point begin, t_point end, t_data *data, int color)
// {
// 	float	slope;

// 	slope = ((float)end.y - (float)begin.y) / ((float)end.x - (float)begin.x);
// 	while (begin.x <= end.x)
// 	{
// 		my_mlx_pixel_put(data, begin.x, begin.y, color);
// 		begin.x += 1;
// 		begin.y = (int)(slope * begin.x);
// 	}
// }

// t_image	ft_new_sprite(void *mlx, char *path)
// {
// 	t_image	img;

// 	img.pointer = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
// 	img.pixels = mlx_get_data_addr(&img, &img.bits_per_pixel, \
// 					&img.line_size, &img.endian);
// 	return (img);
// }
