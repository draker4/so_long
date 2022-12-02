/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_board.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:38:25 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/02 19:22:46 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

static void	ft_sprite_to_window(t_game *game, t_map *current)
{
	if (current->type == '1')
		ft_create_wall(game, current);
	if (current->type == '0')
		ft_create_background(game, current);
	else if (current->type == 'P')
		ft_create_player_sprite(game, current);
	else if (current->type == 'E')
		ft_create_exit(game, current);
	else if (current->type == 'C')
		ft_create_collectible(game, current);
}

static void	ft_initialize_ptr_sprites(t_game *game)
{
	game->sprites.ptr_sprite_background = ft_create_img(game, \
		PATH_SPRITE_BACKGROUND);
	game->sprites.ptr_sprite_block = ft_create_img(game, \
		PATH_SPRITE_BLOCK);
	game->sprites.ptr_sprite_collectible = ft_create_img(game, \
		PATH_SPRITE_COLLECTIBLE);
	game->sprites.ptr_sprite_exit = ft_create_img(game, \
		PATH_SPRITE_EXIT);
	game->sprites.ptr_sprite_ground = ft_create_img(game, \
		PATH_SPRITE_GROUND);
	game->sprites.ptr_sprite_left = ft_create_img(game, \
		PATH_SPRITE_LEFT);
	game->sprites.ptr_sprite_player = ft_create_img(game, \
		PATH_SPRITE_PLAYER);
	game->sprites.ptr_sprite_right = ft_create_img(game, \
		PATH_SPRITE_RIGHT);
	game->sprites.ptr_sprite_top = ft_create_img(game, \
		PATH_SPRITE_TOP);
}

void	ft_create_board(t_game *game, int init)
{
	t_map	*current;

	if (init)
		ft_initialize_ptr_sprites(game);
	current = game->map;
	while (current)
	{
		ft_sprite_to_window(game, current);
		current = current->next;
	}
}
