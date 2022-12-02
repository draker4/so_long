/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:47:18 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/02 19:56:12 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

void	ft_create_wall(t_game *game, t_map *current)
{
	if (current->up && current->up->type != '1')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.\
ptr_sprite_ground, (current->pos.x) * SPRITES, (current->pos.y) * SPRITES);
	else if (current->down && current->down->type != '1')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.\
ptr_sprite_top, (current->pos.x) * SPRITES, (current->pos.y) * SPRITES);
	else if (current->left && current->left->type != '1')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.\
ptr_sprite_left, (current->pos.x) * SPRITES, (current->pos.y) * SPRITES);
	else if (current->right && current->right->type != '1')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.\
ptr_sprite_right, (current->pos.x) * SPRITES, (current->pos.y) * SPRITES);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.\
ptr_sprite_block, (current->pos.x) * SPRITES, (current->pos.y) * SPRITES);
}

void	ft_create_background(t_game *game, t_map *current)
{
	mlx_put_image_to_window(game->mlx, game->win, game->sprites.\
ptr_sprite_background, (current->pos.x) * SPRITES, (current->pos.y) * SPRITES);
}

void	ft_create_player_sprite(t_game *game, t_map *current)
{
	int	frame;

	frame = game->p_right * (SPRITES / 5);
	mlx_put_image_to_window(game->mlx, game->win, game->sprites.\
ptr_sprite_background, (current->pos.x) * SPRITES, (current->pos.y) * SPRITES);
	mlx_put_image_to_window(game->mlx, game->win, game->sprites.\
ptr_sprite_player, ((current->pos.x) * SPRITES) + frame, (current->pos.y) * SPRITES);
}

void	ft_create_exit(t_game *game, t_map *current)
{
	mlx_put_image_to_window(game->mlx, game->win, game->sprites.\
ptr_sprite_background, (current->pos.x) * SPRITES, (current->pos.y) * SPRITES);
	mlx_put_image_to_window(game->mlx, game->win, game->sprites.\
ptr_sprite_exit, (current->pos.x) * SPRITES, (current->pos.y) * SPRITES);
}

void	ft_create_collectible(t_game *game, t_map *current)
{
	mlx_put_image_to_window(game->mlx, game->win, game->sprites.\
ptr_sprite_background, (current->pos.x) * SPRITES, (current->pos.y) * SPRITES);
	mlx_put_image_to_window(game->mlx, game->win, game->sprites.\
ptr_sprite_collectible, (current->pos.x) * SPRITES, (current->pos.y) * SPRITES);
}
