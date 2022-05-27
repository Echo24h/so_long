# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gborne <gborne@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 17:10:18 by dalves-p          #+#    #+#              #
#    Updated: 2022/05/27 13:39:44 by gborne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	gcc
SRCS		=	srcs/main.c \
				srcs/hooks.c \
				srcs/init_map.c \
				srcs/init_img.c \
				srcs/init_root.c \
				srcs/init_screen.c \

SRCS_BONUS	=

LIBFT		=	libft/libft.a
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-L ./mlx/ -lmlx -framework OpenGL -framework AppKit -lz
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)
OBJS_BONUS	=	$(SRCS_BONUS:%.c=%.o)

ifeq ($(shell uname), Linux)
MLXFLAGS	=	-L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11
endif

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C libft
			make -C mlx_linux
			$(CC) $(OBJS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

%o:			%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

sanitize: 	$(OBJS)
			make -C libft
			$(CC) $(OBJS) $(LIBFT) $(MLXFLAGS) -g -fsanitize=address $(CFLAGS) -o $(NAME)

bonus: 		$(OBJS_BONUS)
			make -C libft
			$(CC) $(OBJS_BONUS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			$(RM) $(NAME)
			$(RM) *.out
			make fclean -C libft/

re:			fclean all

test:		all
			./so_long maps/map.ber

git:
	@git add .
	@git commit -m "$m"
	@git push
	@echo "Commit sent to github"
# Para chamar: make git m="meu commit"

.PHONY:		all clean fclean re test sanitize
