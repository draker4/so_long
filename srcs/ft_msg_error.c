/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:29:55 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/07 17:24:23 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

int	ft_error(t_map **map, int message, char *line)
{
	ft_lst_clear_map(map);
	free(line);
	if (!message)
		ft_printf("Error\nError while opening the file!\n");
	else if (message == 1)
		ft_printf("Error\nMemory allocation is well secured, try again!\n");
	else if (message == 2)
		ft_printf("Error\nError while closing the file!\n");
	else if (message == 3)
		ft_printf("Error\nPlease use a rectangular map!\n");
	else if (message == 5)
		ft_printf("Error\nThere is an empty line in the map!\n");
	else if (message == 6)
		ft_printf("Error\nPlease use only 'E', 'C', 'P', '0' and '1' \
characters in the map!\n");
	else if (message == 7)
		ft_printf("Error\nPlease select a map with one exit only!\n");
	else if (message == 8)
		ft_printf("Error\nPlease select a map with at least one collectible!\n");
	else if (message == 9)
		ft_printf("Error\nPlease select a map with one player \
starting position only!\n");
	else if (message == 10)
		ft_printf("Error\nPlease select a map surrounded by walls1\n");
	return (0);
}

int	ft_errors(t_map **map, int message, char *line)
{
	ft_lst_clear_map(map);
	free(line);
	if (message == 11)
		ft_printf("Error\nThe map's path doesn't finish with the .ber \
extension!\n");
	if (message == 12)
		ft_printf("Error\nThere is not any valid path in the map !\n");
	else if (message == 13)
		ft_printf("Error\nProblem with a node of my list!\n");
	else if (message == 14)
		ft_printf("Error\nPlease enter one argument and one only1\n");
	else if (message == 15)
		ft_printf("Error\nPlease choose a map with a valid path to the exit!\n");
	return (0);
}

int	ft_error_game(t_game *game, int message)
{
	free(game->win);
	ft_lst_clear_ennemy(&game->ennemy);
	if (message == 16)
		ft_printf("Error\nProgram couldn't init minilibx!\n");
	else if (message == 17)
		ft_printf("Error\nProgram couldn't init a nex window!\n");
	return (0);
}
