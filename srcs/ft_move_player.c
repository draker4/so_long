/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:25:27 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/07 15:46:05 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

static void	ft_change_type(t_game *game, int dir)
{
	game->nb_moves++;
	if (game->player.map->type != 'E' && game->player.map->type != 'X')
		game->player.map->type = '0';
	if (dir == 0)
		game->player.map = game->player.map->right;
	else if (dir == 1)
		game->player.map = game->player.map->left;
	else if (dir == 2)
		game->player.map = game->player.map->down;
	else if (dir == 3)
		game->player.map = game->player.map->up;
	if (game->player.map->type == 'C')
		game->collect.nb_collectibles--;
	if (game->player.map->type != 'E' && game->player.map->type != 'X')
		game->player.map->type = 'P';
	else if (game->player.map->type == 'E' && !game->collect.nb_collectibles)
		game->death = 1;
}

void	ft_adapt_board(t_game *game)
{
	ft_move_player(game);
	ft_move_ennemy(game);
	if (game->player.pos.x + (SPRITES / 2) > game->player.map->pos.x * SPRITES \
	+ SPRITES + SPRITES / 2)
		ft_change_type(game, 0);
	else if (game->player.pos.x - (SPRITES / 2) < game->player.map->pos.x * \
	SPRITES - SPRITES / 2)
		ft_change_type(game, 1);
	else if (game->player.pos.y + (SPRITES / 2) > game->player.map->pos.y * \
	SPRITES + SPRITES + SPRITES / 2)
		ft_change_type(game, 2);
	else if (game->player.pos.y - (SPRITES / 2) < game->player.map->pos.y * \
	SPRITES - SPRITES / 2)
		ft_change_type(game, 3);
}

static void	ft_jump(t_game *game)
{
	int	max_frame;

	max_frame = MAX_FRAME_JUMP;
	if (!(ft_can_move_up(game)))
		game->player.is_jumping = 0;
	else if (game->frame_jump < max_frame / 2)
		game->player.pos.y -= 2 * SP_FALL;
	else if (game->frame_jump < max_frame - max_frame / 4)
		game->player.pos.y -= 1 * SP_FALL;
	else if (game->frame_jump < max_frame)
		game->player.pos.y -= (int)(0.5 * SP_FALL);
	else if (ft_can_move_down(game) && game->frame_jump < 2 * max_frame)
	{
		if (game->frame_jump < max_frame + max_frame / 4)
			game->player.pos.y += (int)(0.5 * SP_FALL);
		else if (game->frame_jump < max_frame + max_frame / 2)
			game->player.pos.y += 1 * SP_FALL;
		else if (game->frame_jump < 2 * max_frame)
			game->player.pos.y += 2 * SP_FALL;
	}
	else
		game->player.is_jumping = 0;
	game->frame_jump++;
}

void	ft_move_player(t_game *game)
{
	if (game->player.dir_right && ft_can_move_right(game) && \
	!ft_can_move_down(game))
		game->player.pos.x += SPEED_PLAYER;
	else if (game->player.dir_right && ft_can_move_right(game) && \
	ft_can_move_down(game))
		game->player.pos.x += 1.5 * SPEED_PLAYER;
	if (game->player.dir_left && ft_can_move_left(game) && \
	!ft_can_move_down(game))
		game->player.pos.x -= SPEED_PLAYER;
	else if (game->player.dir_left && ft_can_move_left(game) && \
	ft_can_move_down(game))
		game->player.pos.x -= 1.5 * SPEED_PLAYER;
	if (game->player.is_jumping && game->gravity)
		ft_jump(game);
	else if (ft_can_move_down(game) && game->gravity)
		game->player.pos.y += 2 * SP_FALL;
	else if (!game->gravity && game->player.dir_up && ft_can_move_up(game))
		game->player.pos.y -= SP_FALL;
	else if (!game->gravity && game->player.dir_down && ft_can_move_down(game))
		game->player.pos.y += SP_FALL;
}
