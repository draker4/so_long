/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:20:54 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/07 16:08:00 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

void	ft_is_jumping(t_game *game)
{
	if (game->player.dir_up && !game->player.is_jumping && \
		!ft_can_move_down(game))
	{
		game->player.is_jumping = 1;
		game->player.anim_jump = 0;
		game->frame_jump = 0;
	}
}

void	ft_end_game(t_game *game, t_data data)
{
	t_map		*current;
	static int	x;
	int			y;

	if (game->countframe == 0 || game->countframe % 2 == 0)
	{
		current = game->map;
		y = 0;
		while (current)
		{
			if (current->pos.x == x && current->pos.y == y)
			{
				ft_put_xpm_to_image(game, current, data, 0);
				y++;
			}
			current = current->next;
		}
		if (x >= game->map->max.x)
			ft_exit_game(game);
		else if (x != game->map->max.x)
			x++;
	}
}
