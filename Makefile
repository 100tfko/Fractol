# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 13:06:03 by lcuevas-          #+#    #+#              #
#    Updated: 2024/02/02 17:39:08 by lcuevas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

MLX42_PATH = libs/MLX42
MLX42 = $(MLX42_PATH)/libmlx42.a

LIBFT_PATH = libs/libft
LIBFT = $(LIBFT_PATH)/libft.a

HEADERS = -I ./libs -I $(MLX42_PATH)/include/MLX42 -I $(LIBFT_PATH)

SRCS =	src/ft_main.c\
		src/ft_aux.c\
		src/ft_error.c\
		src/ft_fractal.c\
		src/ft_hook.c\
		src/ft_color.c

OBJS = $(SRCS:src/%.c=obj/%.o)

# colores?

######################################################

all : $(MLX42) $(LIBFT) $(NAME)

# .SILENT: pa silenciar echos

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX42) $(LIBFT) $(HEADERS) -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MLX42):
	make -C $(MLX42_PATH)

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(FLAGS) -c $< -o $@ $(HEADERS)

clean:
	$(RM) obj
	make -C $(LIBFT_PATH) clean
	make -C $(MLX42_PATH) clean

fclean:
	$(RM) obj $(NAME)
	make -C $(LIBFT_PATH) fclean
	make -C $(MLX42_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
