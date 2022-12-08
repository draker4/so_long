/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ennemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:24:28 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/08 10:24:46 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

static int	ft_ennemy_right(t_game *game, t_ennemy *ennemy)
{
	return (ft_is_not_wall(ennemy->pos.x + SPRITES / 2 + SPEED_ENNEMY, \
	ennemy->pos.y, game) && !ft_is_not_wall(ennemy->pos.x + SPRITES / 2 + \
	SPEED_ENNEMY, ennemy->pos.y + SPRITES / 2 + O_GROUND, game));
}

static int	ft_ennemy_left(t_game *game, t_ennemy *ennemy)
{
	return (ft_is_not_wall(ennemy->pos.x - SPRITES / 2 - SPEED_ENNEMY - \
	+ 2 * O_GROUND, \
	ennemy->pos.y, game) && !ft_is_not_wall(ennemy->pos.x - SPRITES / 2 - \
	SPEED_ENNEMY, ennemy->pos.y + SPRITES / 2 + O_GROUND, game));
}

void	ft_move_ennemy(t_game *game)
{
	t_ennemy	*current;

	current = game->ennemy;
	while (current)
	{
		if (current->dir == 1 && ft_ennemy_right(game, current))
			current->pos.x += SPEED_ENNEMY;
		else if (current->dir == 1 && !ft_ennemy_right(game, current))
			current->dir = -1;
		else if (current->dir == -1 && ft_ennemy_left(game, current))
			current->pos.x -= SPEED_ENNEMY;
		else if (current->dir == -1 && !ft_ennemy_left(game, current))
			current->dir = 1;
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.ennemy.\
			img, current->pos.x - SPRITES / 2 - OFFSET_ENNEMY_X, \
			current->pos.y + OFFSET_ENNEMY_Y - SPRITES / 2);
		current = current->next;
	}
	ft_is_ennemy(game);
}

static int	ft_collision_ennemy(t_game *game, t_ennemy *current)
{
	return (((game->player.pos.x + SPRITES / 2 > current->pos.x - \
			SPRITES / 2 + O_COL_ENNEMY && game->player.pos.x + SPRITES / 2 < \
			current->pos.x + SPRITES / 2) || (game->player.pos.x - SPRITES / \
			2 < current->pos.x + SPRITES / 2 && game->player.pos.x - SPRITES / \
			2 > current->pos.x - SPRITES / 2)) && ((game->player.pos.y - \
			SPRITES / 2 < current->pos.y + SPRITES / 2 + O_COL_ENNEMY && \
			game->player.pos.y - SPRITES / 2 > current->pos.y - SPRITES / 2 - \
			O_COL_ENNEMY) || (game->player.pos.y + SPRITES / 2 > current->pos.y \
			- SPRITES / 2 + O_COL_ENNEMY && game->player.pos.y + SPRITES / 2 < \
			current->pos.y + SPRITES / 2 + O_COL_ENNEMY)));
}

void	ft_is_ennemy(t_game *game)
{
	t_ennemy	*current;

	current = game->ennemy;
	while (current)
	{
		if (ft_collision_ennemy(game, current))
		{
			if (!game->player.invicible)
			{
				game->player.life--;
				if (game->player.life > 1)
					ft_printf("You lose one life. You have now %d lives.\n", \
					game->player.life);
				else
					ft_printf("You lose one life. You have now %d life.\n", \
					game->player.life);
				game->player.hit = 1;
				game->player.invicible = 1;
				ft_rect_heart(game);
			}
			else if (game->player.attack)
				ft_free_ennemy(&game->ennemy, current);
		}
		current = current->next;
	}
}
