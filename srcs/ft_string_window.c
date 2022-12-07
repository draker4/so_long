/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:20:40 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/06 11:22:30 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

static void	ft_str_move(char *str, char *copy, char *nb, t_game *game)
{
	int	i;

	i = 0;
	while (copy[i])
	{
		str[i] = copy[i];
		i++;
	}
	str[i] = '\0';
	ft_strlcat(str, nb, ft_strlen(nb) + ft_strlen(str) + 1);
	mlx_string_put(game->mlx, game->win, SPRITES, (game->map->max.y + 1) * \
	SPRITES + SPRITES / 2, 0x0066FF00, str);
}

static void	ft_print_move_term(t_game *game)
{
	static int	moves;

	if (moves != game->nb_moves)
	{
		moves = game->nb_moves;
		ft_printf("Moves = %d\n", moves);
	}
}

void	ft_print_move(t_game *game)
{
	char		*str;
	char		*nb;
	int			len;

	nb = ft_itoa(game->nb_moves);
	if (!nb)
		return ;
	if (game->map->max.x > 4)
		len = ft_strlen(nb) + ft_strlen("Moves = ") + 1;
	else
		len = ft_strlen(nb) + 1;
	str = malloc(sizeof(char) * len);
	if (!str)
	{
		free(nb);
		return ;
	}
	if (game->map->max.x > 4)
		ft_str_move(str, "Moves = ", nb, game);
	else
		mlx_string_put(game->mlx, game->win, SPRITES, (game->map->max.y + 1) * \
		SPRITES + SPRITES / 2, 0x0066FF00, nb);
	ft_print_move_term(game);
	free(nb);
	free(str);
}
