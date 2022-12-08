.PHONY:	all clean fclean re fclean_lib fclean_all

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	so_long

LIBMLX		=	libmlx.dylib

LIBFT		=	libft.a

# ---- Directories ---- #

DIR_OBJS	=	.objs/

DIR_SRCS	=	srcs/

DIR_LIBFT	=	libft/

DIR_MLX		=	mlx/

DIR_HEAD	=	head/

#DIR_HEAD	=	head/

# ---- Files ---- #

HEAD		=	so_long.h			so_long_path.h

SRCS		=	main.c				ft_parsing.c		\
				ft_lst_map.c		ft_error_map.c		\
				ft_check_paths.c	ft_set_up.c			\
				ft_msg_error.c		ft_create_board.c	\
				ft_play_game.c		ft_create_sprites.c	\
				ft_my_mlx.c			ft_game_utils.c		\
				ft_move_player.c	ft_anim_player.c	\
				ft_move_offset.c	ft_handle_event.c	\
				ft_animations.c		ft_string_window.c	\
				ft_move_ennemy.c	ft_lst_ennemy.c		\
				ft_game_utils_2.c

OBJS		=	${SRCS:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p
AR		=	ar rc

# ********* RULES ******** #

all				:	${NAME}

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} Makefile ${LIBMLX} ${addprefix ${DIR_LIBFT}, ${LIBFT}} ${addprefix ${DIR_HEAD}, ${HEAD}}
					${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${DIR_LIBFT} -lft  -L${DIR_MLX} -lmlx -framework OpenGL -framework AppKit

${LIBMLX}		:
					make ${LIBMLX} -C ${DIR_MLX}
					cp ${addprefix ${DIR_MLX}, ${LIBMLX}} .

${addprefix ${DIR_LIBFT}, ${LIBFT}}	:
					make ${LIBFT} -C ${DIR_LIBFT}

# ---- Compiled Rules ---- #

${OBJS}			:	| ${DIR_OBJS}

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c Makefile ${addprefix ${DIR_HEAD}, ${HEAD}}
					${CC} ${CFLAGS} -Imlx -I ${DIR_HEAD} -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

# ---- Usual Commands ---- #
					
fclean_lib		:	
					make fclean -C ${DIR_LIBFT}
					make clean -C ${DIR_MLX}

clean			:
					${RM} ${DIR_OBJS}

fclean			:	clean
					${RM} ${NAME} ${LIBMLX}

fclean_all		:	fclean fclean_lib

re				:	fclean all
