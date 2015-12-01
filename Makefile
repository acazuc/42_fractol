# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2015/12/01 07:59:28 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Wextra -Werror

SRCS = fractol.c window_init.c mandelbrot.c julia.c burningship.c env_init.c event_listener.c draw.c

OBJS = $(SRCS:.c=.o)

LIBRARY = -lm -L libft/ -lft -L minilibx/ -lmlx -framework OpenGL -framework AppKit

all: libft $(NAME)

$(NAME): $(OBJS)
	@gcc $(FLAGS) -o $(NAME) $^ $(LIBRARY)

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $<

.PHONY: clean fclean re libft

libft:
	@(cd libft/; make)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
