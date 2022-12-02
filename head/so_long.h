/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:49:46 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/02 19:23:17 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <../libft/libft.h>
# include <mlx.h>
# include <fcntl.h>

# define PATH_SPRITE_PLAYER 		"./sprites/player.xpm"
# define PATH_SPRITE_EXIT 			"./sprites/flag.xpm"
# define PATH_SPRITE_COLLECTIBLE	"./sprites/collectible.xpm"
# define PATH_SPRITE_GROUND			"./sprites/ground.xpm"
# define PATH_SPRITE_RIGHT			"./sprites/wall_right.xpm"
# define PATH_SPRITE_LEFT			"./sprites/wall_left.xpm"
# define PATH_SPRITE_TOP			"./sprites/wall_top.xpm"
# define PATH_SPRITE_BLOCK			"./sprites/wall_block.xpm"
# define PATH_SPRITE_BACKGROUND		"./sprites/background.xpm"

# define WINDOW_TITLE	"./so_long by bperriol, thank you bperriol \
you're the best !"

# define SPRITES	32

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

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
	char			type;
	char			start_type;
	t_vector		pos;
	t_vector		max;
	struct s_map	*next;
	struct s_map	*up;
	struct s_map	*down;
	struct s_map	*left;
	struct s_map	*right;
}	t_map;

typedef struct s_player
{
	t_map	*map;
}	t_player;

typedef struct s_sprites
{
	void	*ptr_sprite_player;
	void	*ptr_sprite_collectible;
	void	*ptr_sprite_background;
	void	*ptr_sprite_exit;
	void	*ptr_sprite_ground;
	void	*ptr_sprite_top;
	void	*ptr_sprite_left;
	void	*ptr_sprite_right;
	void	*ptr_sprite_block;
}	t_sprites;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_map			*map;
	t_player		player;
	int				nb_collectibles;
	int				nb_moves;
	t_sprites		sprites;
}	t_game;

//prototypes parsing
int		ft_start_game(t_game *game, char *path);

//prototypes set up t_game
int		ft_complete_map(t_map **map);
int		ft_set_up(t_game *game);
void	ft_set_up_sprites(t_game *game);

//prototypes check paths
int		ft_wrong_path(char *str);
int		ft_verif_path(t_game *game);

//prototypes creation board
void	ft_create_board(t_game *game, int init);

//prototypes errors map
int		ft_verif_walls(t_map *map);//, int max_x, int max_y);
int		ft_verif_char(t_map *map);
int		ft_verif_rect(t_map *map);//, int *max_x, int *max_y);

//prototypes listes t_map
t_map	*ft_new_elem(char c, int x, int y);
void	ft_lst_clear_map(t_map **map);
void	ft_lst_add_back(t_map **map, t_map *new);
t_map	*ft_find_node(t_map *map, int x, int y);

//prototypes error messages
int		ft_error(t_map **map, int message, char *line);
int		ft_errors(t_map **map, int message, char *line);
int		ft_error_game(t_game *game, int message);

//prototypes play game
int		ft_play_game(t_game *game);

//prototypes creation sprites
void	ft_create_wall(t_game *game, t_map *current);
void	ft_create_background(t_game *game, t_map *current);
void	ft_create_player_sprite(t_game *game, t_map *current);
void	ft_create_exit(t_game *t_game, t_map *current);
void	ft_create_collectible(t_game *game, t_map *current);

//prototypes my minilibx
int		ft_handle_keypress(int keycode, t_game *game);
void	*ft_create_img(t_game *game, char *path);

#endif
