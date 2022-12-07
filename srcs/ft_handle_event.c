/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:29:54 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/07 16:43:36 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

int	ft_handle_keypress(int keycode, t_game *game)
{
	if (keycode == 53)
		ft_exit_game(game);
	else if (keycode == 2 || keycode == 124)
	{
		game->player.dir_sprite = 1;
		game->player.dir_right = 1;
	}
	else if (keycode == 0 || keycode == 123)
	{
		game->player.dir_sprite = -1;
		game->player.dir_left = 1;
	}
	else if (keycode == 13 || keycode == 126 || keycode == 49)
		game->player.dir_up = 1;
	else if (keycode == 1 || keycode == 125)
		game->player.dir_down = 1;
	else if (keycode == 11 || keycode == 12)
	{
		game->player.invicible = 1;
		game->player.attack = 1;
	}
	else if (keycode == 5)
		game->gravity = (game->gravity + 1) % 2;
	return (0);
}

int	ft_handle_keyrelease(int keycode, t_game *game)
{
	if (keycode == 2 || keycode == 124)
		game->player.dir_right = 0;
	else if (keycode == 0 || keycode == 123)
		game->player.dir_left = 0;
	else if (keycode == 13 || keycode == 126 || keycode == 49)
		game->player.dir_up = 0;
	else if (keycode == 1 || keycode == 125)
		game->player.dir_down = 0;
	return (0);
}

static void	ft_free_next_images(t_game *game)
{
	if (game->sprites.top.img)
		mlx_destroy_image(game->mlx, game->sprites.top.img);
	if (game->sprites.victory.img)
		mlx_destroy_image(game->mlx, game->sprites.victory.img);
	if (game->sprites.heart.img)
		mlx_destroy_image(game->mlx, game->sprites.heart.img);
	if (game->sprites.death.img)
		mlx_destroy_image(game->mlx, game->sprites.death.img);
}

static void	ft_free_images(t_game *game)
{
	if (game->sprites.block.img)
		mlx_destroy_image(game->mlx, game->sprites.block.img);
	if (game->sprites.ennemy.img)
		mlx_destroy_image(game->mlx, game->sprites.ennemy.img);
	if (game->sprites.collect.img)
		mlx_destroy_image(game->mlx, game->sprites.collect.img);
	if (game->sprites.exit.img)
		mlx_destroy_image(game->mlx, game->sprites.exit.img);
	if (game->sprites.ground.img)
		mlx_destroy_image(game->mlx, game->sprites.ground.img);
	if (game->sprites.bkground.img)
		mlx_destroy_image(game->mlx, game->sprites.bkground.img);
	if (game->sprites.left.img)
		mlx_destroy_image(game->mlx, game->sprites.left.img);
	if (game->sprites.player.img)
		mlx_destroy_image(game->mlx, game->sprites.player.img);
	if (game->sprites.right.img)
		mlx_destroy_image(game->mlx, game->sprites.right.img);
	ft_free_next_images(game);
}

int	ft_exit_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	ft_free_images(game);
	mlx_destroy_window(game->mlx, game->win);
	ft_lst_clear_map(&(game->map));
	ft_lst_clear_ennemy(&(game->ennemy));
	free(game->win);
	exit(0);
}
