/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:45:48 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/02 13:17:41 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

int	ft_verif_rect(t_map *map)
{
	t_map	*current;

	current = map;
	while (current && current->pos.y == 0)
	{
		map->max.x = current->pos.x;
		current = current->next;
	}
	if (!current)
		return (ft_error(&map, 4, NULL));
	while (current)
	{
		if ((current->pos.x < map->max.x && current->next \
				&& current->next->pos.y != current->pos.y) \
				|| current->pos.x > map->max.x \
				|| (current->pos.x < map->max.x && current->next == NULL))
			return (ft_error(&map, 3, NULL));
			map->max.y = current->pos.y;
		current = current->next;
	}
	return (1);
}

static int	ft_is_char_ok(char c, int *exit, int *collectible, \
	int *player_start)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		return (0);
	if (c == 'E')
		*exit += 1;
	if (c == 'C')
		*collectible += 1;
	if (c == 'P')
		*player_start += 1;
	return (1);
}

int	ft_verif_char(t_map *map)
{
	t_map	*current;
	int		exit;
	int		collectible;
	int		player_start;

	exit = 0;
	collectible = 0;
	player_start = 0;
	current = map;
	while (current)
	{
		if (current->type == '\n')
			return (ft_error(&map, 5, NULL));
		if (!ft_is_char_ok(current->type, &exit, &collectible, &player_start))
			return (ft_error(&map, 6, NULL));
		current = current->next;
	}
	if (exit != 1)
		return (ft_error(&map, 7, NULL));
	if (collectible < 1)
		return (ft_error(&map, 8, NULL));
	if (player_start != 1)
		return (ft_error(&map, 9, NULL));
	return (1);
}

int	ft_verif_walls(t_map *map)//, int max_x, int max_y)
{
	t_map	*current;

	current = map;
	while (current)
	{
		if ((!current->pos.x || !current->pos.y || current->pos.x == map->max.x \
			|| current->pos.y == map->max.y) && current->type != '1')
			return (ft_error(&map, 10, NULL));
		current = current->next;
	}
	return (1);
}
