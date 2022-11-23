/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:19:31 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/23 19:39:11 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../head/so_long.h"

int	ft_error(t_map **map, int message, char *line)
{
	ft_lst_clear_map(map);
	free(line);
	if (!message)
		ft_printf("Error\nError while opening the file !\n");
	else if (message == 1)
		ft_printf("Error\nLe malloc est bien securise, ressaye !\n");
	else if (message == 2)
		ft_printf("Error\nError while closing the file !\n");
	return (0);
}

int	ft_fill_map(t_map **map, char *str, int y)
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

int	ft_read_file(t_map	**map, int fd)
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

int	ft_initialize_map(t_map	**map, char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_error(map, 0, NULL));
	if (!ft_read_file(map, fd))
		return (0);
	if (close(fd) == -1)
		return (ft_error(map, 2, NULL));
	return (1);
}

