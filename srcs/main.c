/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:49:23 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/07 15:58:18 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_errors(NULL, 14, NULL));
	if (!ft_start_game(&game, argv[1]))
		return (0);
	if (!ft_play_game(&game))
		return (0);
	ft_lst_clear_map(&(game.map));
	ft_lst_clear_ennemy(&(game.ennemy));
	return (0);
}
