/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:51:25 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/02 13:25:11 by bperriol         ###   ########lyon.fr   */
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

int	ft_set_up(t_game *game)
{
	t_map	*current;

	current = (*game).map;
	while (current)
	{
		if (current->type == 'P')
			(*game).player.map = current;
		else if (current->type == 'C')
			(*game).nb_collectibles += 1;
		current = current->next;
	}
	return (1);
}
