/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:29:32 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/06 17:37:43 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

t_map	*ft_new_elem(char c, int x, int y)
{
	t_map	*elem;

	elem = malloc(sizeof(t_map));
	if (!elem)
		return (NULL);
	elem->next = NULL;
	elem->up = NULL;
	elem->down = NULL;
	elem->left = NULL;
	elem->right = NULL;
	elem->type = c;
	elem->start_type = c;
	elem->pos.x = x;
	elem->pos.y = y;
	return (elem);
}

void	ft_lst_clear_map(t_map **map)
{
	t_map	*current;
	t_map	*previous;

	if (!map || *map == NULL)
		return ;
	current = *map;
	while (current)
	{
		previous = current;
		current = current->next;
		free(previous);
	}
	*map = NULL;
}

void	ft_lst_add_back(t_map **map, t_map *new)
{
	t_map	*current;

	if (map && *map)
	{
		current = *map;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	else if (map)
		*map = new;
}

t_map	*ft_find_node(t_map *map, int x, int y)
{
	t_map	*current;

	current = map;
	while (current)
	{
		if (current->pos.x == x && current->pos.y == y)
			return (current);
		current = current->next;
	}
	return (NULL);
}
