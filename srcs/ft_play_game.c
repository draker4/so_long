/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:02:06 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/07 17:03:52 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

static int	ft_render_next_frame(t_game *game)
{
	if (game->countframe == 99)
		game->countframe = 0;
	else
		game->countframe++;
	if (!game->death)
	{
		ft_invicibility(game);
		ft_is_jumping(game);
		mlx_clear_window(game->mlx, game->win);
		mlx_put_image_to_window(game->mlx, game->win, game->data.img, 0, 0);
		ft_choose_anims(game);
		ft_adapt_board(game);
		ft_print_move(game);
		ft_move_board(game);
	}
	else
	{
		if (!game->collect.nb_collectibles)
			ft_end_game(game, game->sprites.victory);
		else
			ft_end_game(game, game->sprites.death);
		mlx_put_image_to_window(game->mlx, game->win, game->data.img, 0, 0);
	}
	return (1);
}

int	ft_play_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!(game->mlx))
		return (ft_error_game(game, 16));
	game->win = mlx_new_window(game->mlx, (game->map->max.x + 1) \
	* (SPRITES), (game->map->max.y + 2) * (SPRITES), WINDOW_TITLE);
	if (!(game->win))
		return (ft_error_game(game, 17));
	game->data.img = mlx_new_image(game->mlx, (game->map->max.x + 1) \
	* (SPRITES), (game->map->max.y + 2) * (SPRITES));
	game->data.addr = mlx_get_data_addr(game->data.img, &game->\
	data.bits_per_pixel, &game->data.line_length, &game->data.endian);
	ft_initialize_ptr_sprites(game);
	ft_create_board(game);
	mlx_hook(game->win, 2, 1L << 0, &ft_handle_keypress, game);
	mlx_hook(game->win, 3, 1L << 1, &ft_handle_keyrelease, game);
	mlx_hook(game->win, 17, 0, &ft_exit_game, game);
	mlx_loop_hook(game->mlx, &ft_render_next_frame, game);
	mlx_loop(game->mlx);
	return (1);
}
