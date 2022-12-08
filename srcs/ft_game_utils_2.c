/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:20:54 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/08 15:20:01 by bperriol         ###   ########lyon.fr   */
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

static void	ft_write_win(t_game *game)
{
	if (!game->collect.nb_collectibles)
		ft_printf("You won! VICTORY!\n");
	else
		ft_printf("You lose! Try again you can do it !\n");
}

static void	ft_end_game(t_game *game, t_data data)
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
		{
			ft_write_win(game);
			ft_exit_game(game);
		}
		else if (x != game->map->max.x)
			x++;
	}
}

void	ft_send_end(t_game *game)
{
	if (game->won)
		ft_end_game(game, game->sprites.victory);
	else if (game->death)
		ft_end_game(game, game->sprites.death);
	mlx_put_image_to_window(game->mlx, game->win, game->data.img, 0, 0);
}
