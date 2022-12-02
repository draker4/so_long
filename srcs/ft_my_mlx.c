/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:16:54 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/02 19:53:17 by bperriol         ###   ########lyon.fr   */
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

void	*ft_create_img(t_game *game, char *path)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(game->mlx, path, &img_width, &img_height);
	return (img);
}

static void	ft_exit_game(t_game *game)
{
	if (game->sprites.ptr_sprite_block)
		mlx_destroy_image(game->mlx, game->sprites.ptr_sprite_block);
	if (game->sprites.ptr_sprite_collectible)
		mlx_destroy_image(game->mlx, game->sprites.ptr_sprite_collectible);
	if (game->sprites.ptr_sprite_exit)
		mlx_destroy_image(game->mlx, game->sprites.ptr_sprite_exit);
	if (game->sprites.ptr_sprite_ground)
		mlx_destroy_image(game->mlx, game->sprites.ptr_sprite_ground);
	if (game->sprites.ptr_sprite_left)
		mlx_destroy_image(game->mlx, game->sprites.ptr_sprite_left);
	if (game->sprites.ptr_sprite_player)
		mlx_destroy_image(game->mlx, game->sprites.ptr_sprite_player);
	if (game->sprites.ptr_sprite_right)
		mlx_destroy_image(game->mlx, game->sprites.ptr_sprite_right);
	if (game->sprites.ptr_sprite_top)
		mlx_destroy_image(game->mlx, game->sprites.ptr_sprite_top);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

static void	ft_move_player(t_game *game, int dir)
{
	if (dir == 0 && game->player.map->right->type != '1')
	{
		//game->player.map->type = '0';
		//game->player.map->right->type = 'P';
		game->p_right = 1;
		//game->player.map = game->player.map->right;
	}
	else if (dir == 1 && game->player.map->left->type != '1')
	{
		game->player.map->type = '0';
		game->player.map->left->type = 'P';
		game->player.map = game->player.map->left;
	}
	else if (dir == 2 && game->player.map->up->type != '1')
	{
		game->player.map->type = '0';
		game->player.map->up->type = 'P';
		game->player.map = game->player.map->up;
	}
	else if (dir == 3 && game->player.map->down->type != '1')
	{
		game->player.map->type = '0';
		game->player.map->down->type = 'P';
		game->player.map = game->player.map->down;
	}
}

int	ft_handle_keypress(int keycode, t_game *game)
{
	ft_printf("keycode = %d\n", keycode);
	if (keycode == 53)
		ft_exit_game(game);
	else if (keycode == 2 || keycode == 124)
		ft_move_player(game, 0);
	else if (keycode == 0 || keycode == 123)
		ft_move_player(game, 1);
	else if (keycode == 13 || keycode == 126)
		ft_move_player(game, 2);
	else if (keycode == 1 || keycode == 125)
		ft_move_player(game, 3);
	return (0);
}
