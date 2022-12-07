/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_ennemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:34:55 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/07 16:24:19 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

t_ennemy	*ft_new_ennemy(t_vector pos, t_map *map)
{
	t_ennemy	*ennemy;

	ennemy = malloc(sizeof(t_ennemy));
	if (!ennemy)
		return (NULL);
	ennemy->dir = 1;
	ennemy->map = map;
	ennemy->pos = pos;
	ennemy->next = NULL;
	return (ennemy);
}

void	ft_lst_add_ennemy(t_ennemy **ennemy, t_ennemy *new)
{
	t_ennemy	*current;

	if (ennemy && *ennemy)
	{
		current = *ennemy;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	else if (ennemy)
		*ennemy = new;
}

void	ft_lst_clear_ennemy(t_ennemy **ennemy)
{
	t_ennemy	*current;
	t_ennemy	*previous;

	if (!ennemy || *ennemy == NULL)
		return ;
	current = *ennemy;
	while (current)
	{
		previous = current;
		current = current->next;
		free(previous);
	}
	*ennemy = NULL;
}

void	ft_free_ennemy(t_ennemy **ennemy, t_ennemy *to_free)
{
	if (*ennemy)
	{
		if (*ennemy == to_free)
		{
			*ennemy = (*ennemy)->next;
			free(to_free);
		}
		else
			ft_free_ennemy(&(*ennemy)->next, to_free);
	}
}
