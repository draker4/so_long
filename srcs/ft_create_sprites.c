/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:47:18 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/07 12:35:07 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

static void	ft_initialize_size_next(t_game *game)
{
	game->sprites.ennemy.size.x = SPRITES_ENNEMY_X;
	game->sprites.ennemy.size.y = SPRITES_ENNEMY_Y;
	game->sprites.heart.size.x = SPRITES;
	game->sprites.heart.size.y = SPRITES;
	game->sprites.victory.size.x = SPRITES;
	game->sprites.victory.size.y = SPRITES;
	game->sprites.death.size.x = SPRITES;
	game->sprites.death.size.y = SPRITES;
}

static void	ft_initialize_size(t_game *game)
{
	game->sprites.bkground.size.x = SPRITES;
	game->sprites.bkground.size.y = SPRITES;
	game->sprites.block.size.x = SPRITES;
	game->sprites.block.size.y = SPRITES;
	game->sprites.ground.size.x = SPRITES;
	game->sprites.ground.size.y = SPRITES;
	game->sprites.left.size.x = SPRITES;
	game->sprites.left.size.y = SPRITES;
	game->sprites.right.size.x = SPRITES;
	game->sprites.right.size.y = SPRITES;
	game->sprites.top.size.x = SPRITES;
	game->sprites.top.size.y = SPRITES;
	game->sprites.collect.size.x = SPRITES_COLLECT_X;
	game->sprites.collect.size.y = SPRITES_COLLECT_Y;
	game->sprites.player.size.x = SPRITES_PLAYER_X;
	game->sprites.player.size.y = SPRITES_PLAYER_Y;
	game->sprites.exit.size.x = SPRITES;
	game->sprites.exit.size.y = SPRITES;
	ft_initialize_size_next(game);
}

void	ft_initialize_ptr_sprites(t_game *game)
{
	ft_create_sprite(game, &game->sprites.bkground, PATH_SPRITE_BACKGROUND);
	ft_create_sprite(game, &game->sprites.block, PATH_SPRITE_BLOCK);
	ft_create_sprite(game, &game->sprites.ground, PATH_SPRITE_GROUND);
	ft_create_sprite(game, &game->sprites.left, PATH_SPRITE_LEFT);
	ft_create_sprite(game, &game->sprites.right, PATH_SPRITE_RIGHT);
	ft_create_sprite(game, &game->sprites.top, PATH_SPRITE_TOP);
	ft_create_sprite(game, &game->sprites.collect, PATH_SPRITE_COLLECT1);
	ft_create_sprite(game, &game->sprites.exit, PATH_SPRITE_EXIT);
	ft_create_sprite(game, &game->sprites.player, PATH_SPRITE_PLAYER1);
	ft_create_sprite(game, &game->sprites.ennemy, PATH_ENNEMY_1);
	ft_create_sprite(game, &game->sprites.heart, PATH_HEART);
	ft_create_sprite(game, &game->sprites.victory, PATH_VICTORY);
	ft_create_sprite(game, &game->sprites.death, PATH_DEATH);
	ft_initialize_size(game);
}

void	ft_create_wall(t_game *game, t_map *current)
{
	if (current->up && current->up->type != '1')
		ft_put_xpm_to_image(game, current, game->sprites.ground, 0);
	else if (current->down && current->down->type != '1')
		ft_put_xpm_to_image(game, current, game->sprites.top, 0);
	else if (current->left && current->left->type != '1')
		ft_put_xpm_to_image(game, current, game->sprites.left, 0);
	else if (current->right && current->right->type != '1')
		ft_put_xpm_to_image(game, current, game->sprites.right, 0);
	else
		ft_put_xpm_to_image(game, current, game->sprites.block, 0);
}
