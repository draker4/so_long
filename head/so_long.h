/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:49:46 by bperriol          #+#    #+#             */
/*   Updated: 2022/12/08 12:22:51 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <../libft/libft.h>
# include <mlx.h>
# include <fcntl.h>
# include "so_long_path.h"

# define WINDOW_TITLE	"./so_long by bperriol, thank you bperriol \
you're the best !"

# define SPRITES			32
# define SPRITES_PLAYER_X	32
# define SPRITES_PLAYER_Y	30
# define SPRITES_COLLECT_X	24
# define SPRITES_COLLECT_Y	24
# define SPRITES_ENNEMY_X	72
# define SPRITES_ENNEMY_Y	32

# define SPEED_PLAYER				2
# define SP_FALL					3
# define SPEED_ENNEMY				2
# define O_GROUND					10 //offset detection ground in pixels
# define OFFSET_ENNEMY_Y			3  //offset ennemy feet on the ground
# define OFFSET_ENNEMY_X			10  //offset ennemy against walls
# define O_COL_ENNEMY				20  //offset collision against ennemy
# define MAX_FRAME_JUMP				23
# define MAX_FRAME_INVICIBILITY		50
# define MAX_LIFE					5

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
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_vector	size;
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
	t_map		*map;
	t_vector	pos;
	int			dir_right;
	int			dir_left;
	int			dir_up;
	int			dir_down;
	int			nb_sprite;
	int			is_jumping;
	int			attack;
	int			anim_jump;
	int			dir_sprite;
	int			life;
	int			invicible;
	int			hit;
}	t_player;

typedef struct s_ennemy
{
	int				dir;
	t_vector		pos;
	t_map			*map;
	struct s_ennemy	*next;
}	t_ennemy;

typedef struct s_collect
{
	int	nb_collectibles;
	int	nb_sprite_collect;
	int	nb_sprite_exit;
}	t_collect;

typedef struct s_sprites
{
	t_data	player;
	t_data	collect;
	t_data	bkground;
	t_data	exit;
	t_data	ground;
	t_data	top;
	t_data	left;
	t_data	right;
	t_data	block;
	t_data	ennemy;
	t_data	heart;
	t_data	death;
	t_data	victory;
}	t_sprites;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_map			*map;
	t_player		player;
	t_collect		collect;
	t_ennemy		*ennemy;
	int				nb_moves;
	t_sprites		sprites;
	int				countframe;
	int				frame_jump;
	int				frame_invicible;
	int				nb_sprite_ennemy;
	int				gravity;
	int				is_reverse;
	int				death;
	t_data			data;
}	t_game;

//prototypes parsing
int				ft_start_game(t_game *game, char *path);

//prototypes set up t_game
int				ft_complete_map(t_map **map);
int				ft_set_up(t_game *game);
void			ft_set_up_sprites(t_game *game);

//prototypes check paths
int				ft_wrong_path(char *str);
int				ft_verif_path(t_game *game);

//prototypes creation board
void			ft_create_board(t_game *game);
void			ft_move_board(t_game *game);
void			ft_rect_heart(t_game *game);

//prototypes errors map
int				ft_verif_walls(t_map *map);
int				ft_verif_char(t_map *map);
int				ft_verif_rect(t_map *map);

//prototypes listes t_map
t_map			*ft_new_elem(char c, int x, int y);
void			ft_lst_clear_map(t_map **map);
void			ft_lst_add_back(t_map **map, t_map *new);
t_map			*ft_find_node(t_map *map, int x, int y);

//prototypes error messages
int				ft_error(t_map **map, int message, char *line);
int				ft_errors(t_map **map, int message, char *line);
int				ft_error_game(t_game *game, int message);

//prototypes play game
int				ft_play_game(t_game *game);

//prototypes creation sprites
void			ft_initialize_ptr_sprites(t_game *game);
void			ft_create_wall(t_game *game, t_map *current);

//prototypes my minilibx
void			ft_create_sprite(t_game *game, t_data *data, char *path);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
unsigned int	get_pixel_from_xpm(t_data data, int x, int y);
void			ft_put_xpm_to_image(t_game *game, t_map *current, t_data data, \
				int last);
void			ft_reverse_sprite(t_data *data);

//prototypes utils game
int				ft_is_not_wall(int x, int y, t_game *game);
void			ft_choose_anims(t_game *game);
void			ft_choose_anim_player(t_game *game);
void			ft_invicibility(t_game *game);

//prototypes utils game next
void			ft_is_jumping(t_game *game);
void			ft_send_end(t_game *game);

//prototypes move player
void			ft_move_player(t_game *game);
void			ft_adapt_board(t_game *game);
void			ft_reverse_if(t_game *game);

//prototypes anim collect
void			ft_choose_anim_collect(t_game *game);
void			ft_choose_anim_exit(t_game *game);
void			ft_choose_anim_ennemy(t_game *game);

//prototypes movement player
int				ft_can_move_right(t_game *game);
int				ft_can_move_left(t_game *game);
int				ft_can_move_up(t_game *game);
int				ft_can_move_down(t_game *game);

//prototypes handle event
int				ft_handle_keypress(int keycode, t_game *game);
int				ft_handle_keyrelease(int keycode, t_game *game);
int				ft_exit_game(t_game *game);

//prototypes writing to window
void			ft_print_move(t_game *game);

//prototypes ennemy list
t_ennemy		*ft_new_ennemy(t_vector pos, t_map *map);
void			ft_lst_add_ennemy(t_ennemy **ennemy, t_ennemy *new);
void			ft_lst_clear_ennemy(t_ennemy **ennemy);

//prototypes ennemy moves
void			ft_move_ennemy(t_game *game);
void			ft_is_ennemy(t_game *game);
void			ft_free_ennemy(t_ennemy **ennemy, t_ennemy *to_free);

//prototypes anim player
void			ft_anim_player(t_game *game);
void			ft_anim_run(t_game *game);
void			ft_anim_attack(t_game *game);
void			ft_anim_jump(t_game *game);
void			ft_anim_hit(t_game *game);

#endif
