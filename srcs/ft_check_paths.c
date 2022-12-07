/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:07:36 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/06 17:55:54 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

int	ft_wrong_path(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if ((int)ft_strlen(str) != i + 4)
		return (0);
	if (str[++i] != 'b')
		return (0);
	if (str[++i] != 'e')
		return (0);
	if (str[++i] != 'r')
		return (0);
	return (1);
}

static int	ft_verif_exit(t_map *map, int x, int y)
{
	if (map->type == 'p' || map->type == '1')
		return (0);
	if (map->pos.x == x && map->pos.y == y)
		return (1);
	map->type = 'p';
	if (!ft_verif_exit(map->up, x, y))
	{
		if (!ft_verif_exit(map->down, x, y))
		{
			if (!ft_verif_exit(map->left, x, y))
			{
				if (!ft_verif_exit(map->right, x, y))
					return (0);
			}
		}
	}
	return (1);
}

static void	ft_init_map(t_game *game)
{
	t_map	*current;

	current = game->map;
	while (current)
	{
		current->type = current->start_type;
		current = current->next;
	}
}

int	ft_verif_path(t_game *game)
{
	t_map	*current;

	current = game->map;
	while (current)
	{
		if (current->type == 'E')
		{
			if (!ft_verif_exit(game->player.map, current->pos.x,
					current->pos.y))
				return (ft_errors(&(game->map), 15, NULL));
			ft_init_map(game);
		}
		else if (current->type == 'C')
		{
			if (!ft_verif_exit(game->player.map, current->pos.x,
					current->pos.y))
				return (ft_errors(&(game->map), 15, NULL));
			ft_init_map(game);
		}
		current = current->next;
	}
	return (1);
}
