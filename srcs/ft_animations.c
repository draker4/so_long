/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:03:08 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/06 18:30:35 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

void	ft_choose_anim_collect(t_game *game)
{
	if (game->countframe == 0 || game->countframe % 6 == 0)
	{
		if (game->collect.nb_sprite_collect >= 4)
			game->collect.nb_sprite_collect = 0;
		else
			game->collect.nb_sprite_collect++;
	}
	if (game->collect.nb_sprite_collect == 0)
		ft_create_sprite(game, &game->sprites.collect, PATH_SPRITE_COLLECT1);
	else if (game->collect.nb_sprite_collect == 1)
		ft_create_sprite(game, &game->sprites.collect, PATH_SPRITE_COLLECT2);
	else if (game->collect.nb_sprite_collect == 2)
		ft_create_sprite(game, &game->sprites.collect, PATH_SPRITE_COLLECT3);
	else if (game->collect.nb_sprite_collect == 3)
		ft_create_sprite(game, &game->sprites.collect, PATH_SPRITE_COLLECT4);
}

void	ft_choose_anim_exit(t_game *game)
{
	if (game->collect.nb_collectibles > 0)
		ft_create_sprite(game, &game->sprites.exit, PATH_SPRITE_EXIT);
	else if (game->countframe == 0 || game->countframe % 6 == 0)
		game->collect.nb_sprite_exit++;
	if (game->collect.nb_sprite_exit == 1)
		ft_create_sprite(game, &game->sprites.exit, PATH_SPRITE_OPEN1);
	else if (game->collect.nb_sprite_exit == 2)
		ft_create_sprite(game, &game->sprites.exit, PATH_SPRITE_OPEN2);
	else if (game->collect.nb_sprite_exit == 3)
		ft_create_sprite(game, &game->sprites.exit, PATH_SPRITE_OPEN3);
}

void	ft_choose_anim_ennemy(t_game *game)
{
	if (game->countframe == 0 || game->countframe % 6 == 0)
	{
		if (game->nb_sprite_ennemy >= 5)
			game->nb_sprite_ennemy = 0;
		else
			game->nb_sprite_ennemy++;
	}
	if (game->nb_sprite_ennemy == 0)
		ft_create_sprite(game, &game->sprites.ennemy, PATH_ENNEMY_1);
	else if (game->nb_sprite_ennemy == 1)
		ft_create_sprite(game, &game->sprites.ennemy, PATH_ENNEMY_2);
	else if (game->nb_sprite_ennemy == 2)
		ft_create_sprite(game, &game->sprites.ennemy, PATH_ENNEMY_3);
	else if (game->nb_sprite_ennemy == 3)
		ft_create_sprite(game, &game->sprites.ennemy, PATH_ENNEMY_4);
	else if (game->nb_sprite_ennemy == 4)
		ft_create_sprite(game, &game->sprites.ennemy, PATH_ENNEMY_5);
	else if (game->nb_sprite_ennemy == 5)
		ft_create_sprite(game, &game->sprites.ennemy, PATH_ENNEMY_6);
}
