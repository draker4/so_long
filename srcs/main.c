/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:49:23 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/23 18:49:29 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_list	*list;
// 	t_data	img;

// 	list = NULL;
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Bperriol the best !");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
// 	&img.line_length, &img.endian);
// 	my_mlx_pixel_put(&img, 5, 5, 0x00FF00FF);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// 	return (0);
// }

// int	my_key_funct(int keycode, void *param)
// {
// 	ft_printf("key event %d et %p\n", keycode, param);
// 	return (1);
// }


// int	main(void)
// {
// 	void	*mlx;
// 	void	*img;
// 	void	*img2;
// 	void	*win;
// 	char	*relative_path = "./sprites/tile1.xpm";
// 	int		img_width;
// 	int		img_height;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 1920, 1080, "./so_long from bperriol");
// 	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
//  	img2 = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// 	mlx_put_image_to_window(mlx, win, img, 0, 0);
// 	mlx_put_image_to_window(mlx, win, img2, 32, 0);
// 	mlx_put_image_to_window(mlx, win, img2, 0, 32);
//  	mlx_loop(mlx);
// }

int	main(int argc, char **argv)
{
	t_map	*map;

	map = NULL;
	if (argc != 2)
	{
		ft_printf("Error\nPas le bon nombre d'arguments !\n");
		return (0);
	}
	if (!ft_initialize_map(&map, argv[1]))
		return (0);
	while (map)
	{
		ft_printf("%c\n", map->c);
		map = map->next;
	}
	return (0);
}
