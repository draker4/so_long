/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_board.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:38:25 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/08 12:18:48 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

static void	ft_init_sprite_to_window(t_game *game, t_map *current)
{
	int	life;

	life = 0;
	if (current->type == '1')
		ft_create_wall(game, current);
	else
		ft_put_xpm_to_image(game, current, game->sprites.bkground, 0);
}

void	ft_rect_heart(t_game *game)
{
	int	x;
	int	y;

	y = (game->map->max.y + 1) * SPRITES;
	while (y < (game->map->max.y + 2) * SPRITES)
	{
		x = (game->map->max.x - MAX_LIFE - 1) * SPRITES;
		while (x < (game->map->max.x + 1) * SPRITES)
		{
			my_mlx_pixel_put(&game->data, x, y, 0);
			x++;
		}
		y++;
	}
	ft_create_board(game);
}

void	ft_create_board(t_game *game)
{
	t_map	*current;
	int		life;

	life = game->player.life - 1;
	if (life > game->map->max.x - 5)
		life = game->map->max.x - 5;
	current = game->map;
	while (current)
	{
		ft_init_sprite_to_window(game, current);
		if (current->pos.x == game->map->max.x - life && current->pos.y == \
		game->map->max.y && game->map->max.x > 3)
		{
			if (game->map->max.x > 3 + life)
				ft_put_xpm_to_image(game, current, game->sprites.heart, \
				SPRITES);
			life--;
		}
		current = current->next;
	}
}

void	ft_move_board(t_game *game)
{
	t_map	*current;

	current = game->map;
	while (current)
	{
		if (current->type == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->sprites.exit.\
				img, current->pos.x * SPRITES, current->pos.y * SPRITES);
		else if (current->type == 'C')
			mlx_put_image_to_window(game->mlx, game->win, game->sprites.collect.\
				img, current->pos.x * SPRITES, current->pos.y * SPRITES);
		current = current->next;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->sprites.player.img, \
		game->player.pos.x - SPRITES / 2, game->player.pos.y - SPRITES / 2 + \
		(SPRITES - SPRITES_PLAYER_Y));
}
