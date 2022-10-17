# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 16:40:54 by mealjnei          #+#    #+#              #
#    Updated: 2022/10/17 16:47:11 by mealjnei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= so_long
CC		= gcc
RM		= rm -f

SRCS        = srcs/so_long.c srcs/err_utlis.c srcs/win_utlis.c srcs/map_utlis.c srcs/xy_moves.c srcs/valid_check.c
LIBFT_PATH	=	./Libft

LIBFT	=		./Libft/libft.a
MLX	=	./mlx/libmlx.a

MLX_PATH	=	./mlx
INCLUDES =	-I ./includes
CFLAGS	= -Wall -Wextra -Werror -g3

MLX_FLAGS	=	-framework OpenGL -framework AppKit

OBJS        = $(SRCS:.c=.o)

.c.o:
	${CC} ${CFLAGS} $(INCLUDES) -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	@ $(MAKE) -sC $(LIBFT_PATH)
	@export CFLAGS='-Wno-deprecated-declarations'; $(MAKE) -sC $(MLX_PATH)
	$(CC) $(CFLAGS) $(INCLUDES) $(MLX_FLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

all:		${NAME}

clean:
		rm -rf $(OBJS)
		@ $(MAKE) fclean -sC $(LIBFT_PATH)
		@ $(MAKE) clean -sC $(MLX_PATH)

fclean:		clean
		@ ${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
