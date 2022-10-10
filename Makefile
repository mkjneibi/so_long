# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mealjnei <mealjnei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 16:40:54 by mealjnei          #+#    #+#              #
#    Updated: 2022/10/05 18:00:14 by mealjnei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= so_long
CC		= gcc
RM		= rm -f

SRCS        = so_long.c err_utlis.c win_utlis.c map_utlis.c
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
