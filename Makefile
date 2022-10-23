# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 16:40:54 by mealjnei          #+#    #+#              #
#    Updated: 2022/10/23 15:06:15 by mealjnei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRCS        = srcs/so_long.c srcs/err_utlis.c \
				srcs/win_utlis.c srcs/map_utlis.c \
				srcs/xy_moves.c srcs/valid_check.c
LIBFT_PATH	=	./Libft
ECHO = -printf

LIBFT	=		./Libft/libft.a
MLX	=	./mlx/libmlx.a

MLX_PATH	=	./mlx
INCLUDES =	-I ./includes

MLX_FLAGS	=	-framework OpenGL -framework AppKit

OBJS        = $(SRCS:.c=.o)

%.o : %.c
	${CC} ${CFLAGS} $(INCLUDES) -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	@ $(MAKE) -sC $(LIBFT_PATH)
	@export CFLAGS='-Wno-deprecated-declarations'; $(MAKE) -sC $(MLX_PATH)
	@ $(CC) $(CFLAGS) $(INCLUDES) $(MLX_FLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)
	@ $(ECHO) "$(GRE)"
	@ $(ECHO) "\033[2J"
	@ $(ECHO) "SO_LONG is ready to use\n"

all:		${NAME}

clean:
		rm -rf $(OBJS)
		@ $(MAKE) fclean -sC $(LIBFT_PATH)
		@ $(MAKE) clean -sC $(MLX_PATH)

fclean:		clean
		@ ${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re



#------------------------------------------------------------------------------#
#                  COLORS                                                      #
#------------------------------------------------------------------------------#
RED	= \033[1;31m
GRE	= \033[1;32m
YEL	= \033[1;33m
BLU	= \033[1;34m
MAG	= \033[1;35m
CYA	= \033[1;36m
NO_COL = \033[0m