/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:16:54 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/07 12:24:31 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * \
	(data->bits_per_pixel >> 3));
	*(unsigned int *)dst = color;
}

unsigned int	get_pixel_from_xpm(t_data data, int x, int y)
{
	char	*dst;

	dst = data.addr + (y * data.line_length + x * (data.bits_per_pixel >> 3));
	return (*(unsigned int *)dst);
}

void	ft_create_sprite(t_game *game, t_data *data, char *path)
{
	int		img_width;
	int		img_height;

	data->img = mlx_xpm_file_to_image(game->mlx, path, &img_width, &img_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
}

void	ft_put_xpm_to_image(t_game *game, t_map *current, t_data data, int last)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < data.size.y)
	{
		x = 0;
		while (x < data.size.x)
		{
			color = get_pixel_from_xpm(data, x, y);
			if (color != 0xFF000000)
				my_mlx_pixel_put(&game->data, x + (current->pos.x \
				* SPRITES), y + (current->pos.y * SPRITES + last), color);
			x++;
		}
		y++;
	}
}

void	ft_reverse_sprite(t_data *data)
{
	int				x;
	int				y;
	char			*dst_begin;
	char			*dst_end;
	unsigned int	tmp;

	y = 0;
	while (y < data->size.y)
	{
		x = 0;
		while (x < data->size.x / 2 + 1)
		{
			dst_begin = data->addr + (y * data->line_length + \
			(x) * (data->bits_per_pixel >> 3));
			dst_end = data->addr + (y * data->line_length + \
			(data->size.x - x) * (data->bits_per_pixel >> 3));
			tmp = *(unsigned int *)dst_begin;
			*(unsigned int *)dst_begin = *(unsigned int *)dst_end;
			*(unsigned int *)dst_end = tmp;
			x++;
		}
		y++;
	}
}
