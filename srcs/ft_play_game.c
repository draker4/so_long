/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:02:06 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/02 20:05:04 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

static int	ft_render_next_frame(t_game *game)
{
	if (game->p_right)
		game->p_right++;
	if (game->p_right == 5)
	{
		game->player.map->type = '0';
		game->player.map->right->type = 'P';
		game->p_right = 1;
		game->player.map = game->player.map->right;
		game->p_right = 0;
	}
	mlx_clear_window(game->mlx, game->win);
	ft_move_board(game, 0);
	//ft_move_board(game, 1); //je met que collectible et pas background bon courage love you !
	return (0);
}

int	ft_play_game(t_game *game)
{
	game->p_right = 0;
	game->mlx = mlx_init();
	if (!(game->mlx))
		return (ft_error_game(game, 16));
	game->win = mlx_new_window(game->mlx, (game->map->max.x + 1) \
	* (SPRITES), (game->map->max.y + 1) * (SPRITES), WINDOW_TITLE);
	if (!(game->win))
		return (ft_error_game(game, 17));
	ft_create_board(game);
	mlx_hook(game->win, 2, 1L << 0, &ft_handle_keypress, game);
	mlx_loop_hook(game->mlx, &ft_render_next_frame, game);
	mlx_loop(game->mlx);
	return (1);
}
