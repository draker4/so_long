/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:49:46 by bperriol          #+#    #+#             */
/*   Updated: 2022/11/23 18:49:46 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <../libft/libft.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map
{
	char			c;
	int				x;
	int				y;
	struct s_map	*next;
}	t_map;

t_map	*ft_new_elem(char c, int x, int y);
void	ft_lst_clear_map(t_map **map);
int		ft_initialize_map(t_map	**map, char *path);
void	ft_lst_add_back(t_map **map, t_map *new);

#endif
