/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anim_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:52:35 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/07 16:28:18 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

void	ft_anim_player(t_game *game)
{
	game->is_reverse = 0;
	if (game->player.nb_sprite >= 7)
			game->player.nb_sprite = 0;
	else
		game->player.nb_sprite++;
	if (game->player.nb_sprite == 0)
		ft_create_sprite(game, &game->sprites.player, PATH_SPRITE_PLAYER1);
	else if (game->player.nb_sprite == 1)
		ft_create_sprite(game, &game->sprites.player, PATH_SPRITE_PLAYER2);
	else if (game->player.nb_sprite == 2)
		ft_create_sprite(game, &game->sprites.player, PATH_SPRITE_PLAYER3);
	else if (game->player.nb_sprite == 3)
		ft_create_sprite(game, &game->sprites.player, PATH_SPRITE_PLAYER4);
	else if (game->player.nb_sprite == 4)
		ft_create_sprite(game, &game->sprites.player, PATH_SPRITE_PLAYER5);
	else if (game->player.nb_sprite == 5)
		ft_create_sprite(game, &game->sprites.player, PATH_SPRITE_PLAYER6);
	else if (game->player.nb_sprite == 6)
		ft_create_sprite(game, &game->sprites.player, PATH_SPRITE_PLAYER7);
	else if (game->player.nb_sprite == 7)
		ft_create_sprite(game, &game->sprites.player, PATH_SPRITE_PLAYER8);
}

void	ft_anim_run(t_game *game)
{
	game->is_reverse = 0;
	if (game->player.nb_sprite >= 5)
			game->player.nb_sprite = 0;
	else
		game->player.nb_sprite++;
	if (game->player.nb_sprite == 0)
		ft_create_sprite(game, &game->sprites.player, PATH_RUN1);
	else if (game->player.nb_sprite == 1)
		ft_create_sprite(game, &game->sprites.player, PATH_RUN2);
	else if (game->player.nb_sprite == 2)
		ft_create_sprite(game, &game->sprites.player, PATH_RUN3);
	else if (game->player.nb_sprite == 3)
		ft_create_sprite(game, &game->sprites.player, PATH_RUN4);
	else if (game->player.nb_sprite == 4)
		ft_create_sprite(game, &game->sprites.player, PATH_RUN5);
	else if (game->player.nb_sprite == 5)
		ft_create_sprite(game, &game->sprites.player, PATH_RUN6);
}

void	ft_anim_attack(t_game *game)
{
	static int	anim;

	game->is_reverse = 0;
	if (anim == 0)
		ft_create_sprite(game, &game->sprites.player, PATH_ATTACK_1);
	else if (anim == 1)
		ft_create_sprite(game, &game->sprites.player, PATH_ATTACK_2);
	else if (anim == 2)
		ft_create_sprite(game, &game->sprites.player, PATH_ATTACK_3);
	else if (anim == 3)
		ft_create_sprite(game, &game->sprites.player, PATH_ATTACK_4);
	else if (anim == 4)
		ft_create_sprite(game, &game->sprites.player, PATH_ATTACK_1);
	else if (anim == 5)
		ft_create_sprite(game, &game->sprites.player, PATH_ATTACK_2);
	anim++;
	if (anim >= 6)
	{
		game->player.invicible = 0;
		game->player.attack = 0;
		anim = 0;
	}
}

void	ft_anim_jump(t_game *game)
{
	game->is_reverse = 0;
	if (game->player.anim_jump == 0)
		ft_create_sprite(game, &game->sprites.player, PATH_JUMP_1);
	else if (game->player.anim_jump == 1)
		ft_create_sprite(game, &game->sprites.player, PATH_JUMP_2);
	else if (game->player.anim_jump == 2)
		ft_create_sprite(game, &game->sprites.player, PATH_JUMP_3);
	else if (game->player.anim_jump == 3)
	game->player.anim_jump++;
}

void	ft_anim_hit(t_game *game)
{
	static int	anim;

	game->is_reverse = 0;
	if (anim == 0)
		ft_create_sprite(game, &game->sprites.player, PATH_HIT_1);
	else if (anim == 1)
		ft_create_sprite(game, &game->sprites.player, PATH_HIT_2);
	else if (anim == 2)
		ft_create_sprite(game, &game->sprites.player, PATH_HIT_3);
	anim++;
	if (anim >= 2)
	{
		game->player.hit = 0;
		anim = 0;
	}
}
