/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_use.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:29:32 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/23 18:47:44 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

t_map	*ft_new_elem(char c, int x, int y)
{
	t_map	*elem;

	elem = malloc(sizeof(t_map));
	elem->next = NULL;
	elem->c = c;
	elem->x = x;
	elem->y = y;
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
