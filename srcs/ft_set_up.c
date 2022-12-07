/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:51:25 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/07 16:08:02 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

int	ft_complete_map(t_map **map)
{
	t_map	*current;

	current = *map;
	while (current)
	{
		if (ft_find_node(*map, (current->pos.x) + 1, current->pos.y))
			current->right = ft_find_node(*map, (current->pos.x) + 1, \
				current->pos.y);
		if (ft_find_node(*map, (current->pos.x) - 1, current->pos.y))
			current->left = ft_find_node(*map, (current->pos.x) - 1, \
				current->pos.y);
		if (ft_find_node(*map, current->pos.x, (current->pos.y) + 1))
			current->down = ft_find_node(*map, current->pos.x, \
				(current->pos.y) + 1);
		if (ft_find_node(*map, current->pos.x, (current->pos.y) - 1))
			current->up = ft_find_node(*map, current->pos.x, \
				(current->pos.y) - 1);
		current = current->next;
	}
	return (1);
}

static void	ft_set_up_const(t_game *game)
{
	game->countframe = 0;
	game->player.dir_down = 0;
	game->player.dir_left = 0;
	game->player.dir_up = 0;
	game->player.dir_right = 0;
	game->player.nb_sprite = 0;
	game->player.is_jumping = 0;
	game->player.anim_jump = 0;
	game->player.dir_sprite = 1;
	game->gravity = 1;
	game->collect.nb_sprite_collect = 0;
	game->collect.nb_sprite_exit = 0;
	game->is_reverse = 0;
	game->nb_sprite_ennemy = 0;
	game->player.invicible = 0;
	game->frame_invicible = 0;
	game->player.life = MAX_LIFE;
	game->player.hit = 0;
	game->death = 0;
	game->ennemy = NULL;
}

static int	ft_set_up_ennemy(t_game *game, t_map *current)
{
	t_ennemy	*ennemy;
	t_vector	pos;

	pos.x = (current->pos.x) * SPRITES + SPRITES / 2;
	pos.y = (current->pos.y) * SPRITES + SPRITES / 2;
	ennemy = ft_new_ennemy(pos, current);
	if (!ennemy)
	{
		ft_printf("Error\nLe malloc est bien securise, ressaye!\n");
		ft_lst_clear_ennemy(&game->ennemy);
		return (0);
	}
	ft_lst_add_ennemy(&game->ennemy, ennemy);
	return (1);
}

int	ft_set_up(t_game *game)
{
	t_map	*current;

	ft_set_up_const(game);
	current = (*game).map;
	while (current)
	{
		if (current->type == 'P')
		{
			game->player.map = current;
			game->player.pos.x = (current->pos.x) * SPRITES + SPRITES / 2;
			game->player.pos.y = (current->pos.y) * SPRITES + SPRITES / 2;
		}
		else if (current->type == 'C')
			game->collect.nb_collectibles += 1;
		else if (current->type == 'X')
			if (!ft_set_up_ennemy(game, current))
				return (0);
		current = current->next;
	}
	return (1);
}
