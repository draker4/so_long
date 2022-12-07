/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:16:22 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/07 15:58:07 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

int	ft_is_not_wall(int x, int y, t_game *game)
{
	t_map	*current;

	current = game->map;
	while (current)
	{
		if (current->pos.x == x / SPRITES && current->pos.y == y / SPRITES)
		{
			if (current->type == '1')
				return (0);
			else
				return (1);
		}
		current = current->next;
	}
	return (0);
}

void	ft_choose_anim_player(t_game *game)
{
	if (game->player.attack && (game->countframe == 0 || \
	game->countframe % 5 == 0))
		ft_anim_attack(game);
	else if (game->player.hit)
	{
		if (game->countframe == 0 || game->countframe % 20 == 0)
			ft_anim_hit(game);
	}
	else if (game->player.is_jumping && (game->countframe == 0 \
	|| game->countframe % 5 == 0) && game->frame_jump < MAX_FRAME_JUMP)
		ft_anim_jump(game);
	else if (game->player.is_jumping && (game->countframe == 0 \
	|| game->countframe % 5 == 0) && game->frame_jump > MAX_FRAME_JUMP)
		ft_create_sprite(game, &game->sprites.player, PATH_FALL);
	else if (ft_can_move_down(game) && (game->countframe == 0 \
	|| game->countframe % 5 == 0))
		ft_create_sprite(game, &game->sprites.player, PATH_FALL);
	else if ((game->player.dir_right || game->player.dir_left) && (game->\
	countframe == 0 || game->countframe % 5 == 0))
		ft_anim_run(game);
	else if ((!game->player.dir_right && !game->player.dir_left) \
	&& (game->countframe == 0 || game->countframe % 5 == 0))
		ft_anim_player(game);
	ft_reverse_if(game);
}

void	ft_choose_anims(t_game *game)
{
	ft_choose_anim_player(game);
	ft_choose_anim_collect(game);
	ft_choose_anim_exit(game);
	ft_choose_anim_ennemy(game);
}

void	ft_reverse_if(t_game *game)
{
	if (game->player.dir_sprite == 1)
	{
		if (!game->is_reverse)
		{
			game->is_reverse = 1;
			ft_reverse_sprite(&game->sprites.player);
		}
	}	
	else
		game->is_reverse = 0;
}

void	ft_invicibility(t_game *game)
{
	if (!game->player.life)
		game->death = 1;
	if (game->player.invicible)
		game->frame_invicible++;
	if (game->frame_invicible >= MAX_FRAME_INVICIBILITY)
	{
		game->player.invicible = 0;
		game->frame_invicible = 0;
	}
}
