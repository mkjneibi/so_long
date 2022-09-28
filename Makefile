# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mealjnei <mealjnei@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 16:40:54 by mealjnei          #+#    #+#              #
#    Updated: 2022/09/28 16:09:33 by mealjnei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= so_long
CC		= gcc
RM		= rm -f

SRCS        = so_long.c
LIBFT_PATH	=	./Libft

LIBFT	=		./Libft/libft.a
MLX	=	./mlx/libmlx.a

MLX_PATH	=	./mlx

CFLAGS	= -Wall -Wextra -Werror -g3

MLX_FLAGS	=	-framework OpenGL -framework AppKit

OBJS        = $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	@ $(MAKE) -sC $(LIBFT_PATH)
	@ $(MAKE) -sC $(MLX_PATH)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

all:		${NAME}

clean:
		rm -rf $(NAME)

fclean:		clean
	@ ${RM} ${NAME}
	@ rm libmlx.a

re:			fclean all

.PHONY:		all clean fclean re
