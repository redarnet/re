# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: redarnet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/07 11:44:19 by redarnet          #+#    #+#              #
#    Updated: 2020/01/07 11:47:11 by redarnet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = clang
FLAGS =  -Wextra -Werror
MLX  = -lXext -lX11 -lm -lbsd libmlx_Linux.a 
LIBFT = ./libft

SRC  = algo.c \
 	algo2.c\
	checkmap.c\
	decor.c\
	convertisseur.c\
	draw_walls.c\
	erreur.c\
	free.c\
	ft_itoa_base.c\
	main.c\
	map.c\
	parsing2.c\
	parsing.c\
	raycasting.c\
	save.c\
	sprite.c\
	textures.c\
	utils.c\
	get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c

OBJS = $(SRC:.c=.o)


all:  $(NAME) 


minilibx:

$(%.o): $(%.c)
	$(CC) -o $@  $^ 

$(NAME): $(OBJS)
	make -C libft
	make -C minilibx-linux/
	$(CC)  -o $@  $^  libft/libft.a $(MLX)   

clean: 
	make -C libft/ clean 
	make -C minilibx-linux/ clean 
	rm $(OBJS)
fclean: 
	make -C libft/ fclean 
	make -C minilibx-linux/ clean 
	rm $(OBJS)
	rm $(NAME)
re: fclean all
