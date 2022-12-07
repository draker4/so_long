/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_offset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:16:25 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/07 15:52:56 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

int	ft_can_move_right(t_game *game)
{
	return (ft_is_not_wall(game->player.pos.x + SPRITES / \
2 + SPEED_PLAYER, game->player.pos.y, game) && ft_is_not_wall(game->\
player.pos.x + SPRITES / 2 + SPEED_PLAYER, game->player.pos.y + SPRITES / 2 - \
O_GROUND, game) && ft_is_not_wall(game->player.pos.x + SPRITES / 2 + \
SPEED_PLAYER, game->player.pos.y - SPRITES / 2 + O_GROUND, game));
}

int	ft_can_move_left(t_game *game)
{
	return (ft_is_not_wall(game->player.pos.x - SPRITES / \
2 - SPEED_PLAYER, game->player.pos.y, game) && ft_is_not_wall(game->\
player.pos.x - SPRITES / 2 - SPEED_PLAYER, game->player.pos.y + SPRITES / 2 - \
O_GROUND, game) && ft_is_not_wall(game->player.pos.x - SPRITES / 2 - \
SPEED_PLAYER, game->player.pos.y - SPRITES / 2 + O_GROUND, game));
}

int	ft_can_move_up(t_game *game)
{
	return (ft_is_not_wall(game->player.pos.x, game->\
player.pos.y - SPRITES / 2 - SP_FALL, game) && ft_is_not_wall(game->\
player.pos.x + SPRITES / 2 - O_GROUND, game->player.pos.y - SPRITES / 2 - \
SP_FALL, game) && ft_is_not_wall(game->player.pos.x - SPRITES / 2 + \
O_GROUND, game->player.pos.y - SPRITES / 2 - SP_FALL, game));
}

int	ft_can_move_down(t_game *game)
{
	return ((ft_is_not_wall(game->player.pos.x, game->player.pos.y + SPRITES / \
	2 + SP_FALL, game) && ft_is_not_wall(game->player.pos.x + SPRITES / 2 \
	- O_GROUND, game->player.pos.y + SPRITES / 2 + SP_FALL, game) && \
	ft_is_not_wall(game->player.pos.x - SPRITES / 2 + O_GROUND, game->player.\
	pos.y + SPRITES / 2 + SP_FALL, game)) || \
	(ft_is_not_wall(game->player.pos.x, game->player.pos.y + SPRITES / \
	2 + SP_FALL - (SPRITES - SPRITES_PLAYER_Y), game) && \
	ft_is_not_wall(game->player.pos.x + SPRITES / 2 \
	- O_GROUND, game->player.pos.y + SPRITES / 2 + SP_FALL - (SPRITES - \
	SPRITES_PLAYER_Y), game) && ft_is_not_wall(game->player.pos.x - SPRITES / 2 \
	+ O_GROUND, game->player.pos.y + SPRITES / 2 + SP_FALL - (SPRITES - \
	SPRITES_PLAYER_Y), game)));
}
