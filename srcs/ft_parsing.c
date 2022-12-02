/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:19:31 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/02 13:25:22 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

static int	ft_fill_map(t_map **map, char *str, int y)
{
	t_map	*new;
	int		x;
	int		i;

	x = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new = ft_new_elem(str[i], x, y);
		if (!new)
			return (ft_error(map, 1, str));
		ft_lst_add_back(map, new);
		i++;
		x++;
	}
	return (1);
}

static int	ft_read_file(t_map	**map, int fd)
{
	char	*line;
	int		y;

	line = get_next_line(fd);
	if (!line)
		return (ft_error(map, 1, line));
	y = 0;
	while (line)
	{
		if (!ft_fill_map(map, line, y))
			return (ft_error(map, 1, line));
		free(line);
		line = get_next_line(fd);
		if (!line && read(fd, line, 1) != 0)
			return (ft_error(map, 1, line));
		y++;
	}
	free(line);
	return (1);
}

static int	ft_initialize_game(t_map **map, char *path)
{
	int		fd;

	if (!ft_wrong_path(path))
		return (ft_errors(NULL, 11, NULL));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_error(NULL, 0, NULL));
	if (!ft_read_file(map, fd) || !ft_verif_char(*map)
		|| !ft_verif_rect(*map)
		|| !ft_verif_walls(*map)
		|| !ft_complete_map(map))
		return (0);
	if (close(fd) == -1)
		return (ft_error(map, 2, NULL));
	return (1);
}

int	ft_start_game(t_game *game, char *path)
{
	t_map	*map;

	map = NULL;
	if (!ft_initialize_game(&map, path))
		return (0);
	(*game).map = map;
	(*game).nb_moves = 0;
	if (!ft_set_up(game) || !ft_verif_path(game))
		return (0);
	return (1);
}
