# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2016/01/19 08:58:20 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Wextra -Werror -Ofast

CC = gcc

INCLUDES_PATH = includes/

SRCS_PATH = srcs/

SRCS_NAME = fractol.c \
			window_init.c \
			mandelbrot.c \
			julia.c \
			burningship.c \
			env_init.c \
			event_listener.c \
			draw.c \
			pixel_put.c \
			error_quit.c \
			draw_reset.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	@Make -C libft
	@echo " - Making $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY)
	@echo "\033[1;32m"
	@echo "                                      AKEFILEMA                                        "
	@echo "                                  KEFILEMAKEFILEMAK                                    "
	@echo "                              EFILEMAKEFILEMAKEFILEMAK                                 "
	@echo "                      EFILEMAKEFILEMA           KEFILEMA                               "
	@echo "                   KEFILEMAKEFIL                  EMAKEFI                              "
	@echo "                 LEMAKEFILEMAKEF                   ILEMAK                              "
	@echo "                 EFILEMAKEFILEMAK                   EFILE          COMPILATION         "
	@echo "                 MAKEFILEMAK EFILEM    AKEFILEMAKE  FILEM             DONE             "
	@echo "                 AKEFILEMAKEFILEMAKE FILEMAKEFI  MAK EFIL        CONGRATULATION        "
	@echo "                 EMAKEFILEMAKEFILE  MAKEFILEMAK  ILEMAKEF        ______ _______        "
	@echo "                ILEMA  KEFILEMAKEF  ILEMAKEFI    KEFILEMA             |/               "
	@echo "               KEFILEMAKEFILEMAKEFI LEMAKEFI    AKEFILEMA                              "
	@echo "              KEFILEMAKEFILEMAKEF   ILEMAKEFILEMAKEFILEMA                              "
	@echo "             KEFILEMAKEFILEMAKEFILEMAKEFILEMAKEFI  LEMAK                               "
	@echo "            EFILE          MAKEFILEMAKEFILEMA     KEFILE                               "
	@echo "           MAKEF                      ILEMAKE     FILEMA                               "
	@echo "          KEFILE                                 MAKEFI                                "
	@echo "         LEMAKE                                 FILEMA                                 "
	@echo "        KEFILE                                  MAKEFI                                 "
	@echo "        LEMAK                      EFIL        EMAKEF                                  "
	@echo "        ILEM                      AKEFI LEM   AKEFIL                                   "
	@echo "        EMAK                      EFILEMAKEF  ILEMA                         KEFILEMAK  "
	@echo "       EFILE                      MAKEFILEM  AKEFI                        LEMAKEFILEMA "
	@echo "       KEFIL                     EMAKEFILEM AKEFI                       LEMAKE    FILE "
	@echo "       MAKEF                     ILEMAKEFI  LEMAK                     EFILEMA    KEFIL "
	@echo "       EMAKE                    FILEMAKEF  ILEMAK                   EFILEMA     KEFIL  "
	@echo "       EMAKE                    FILEMAKE   FILEMAKEFILEMAKEFILE   MAKEFIL     EMAKE    "
	@echo "        FILE                   MAKEFILE    MAKEFILEMAKEFILEMAKEFILEMAKE      FILEM     "
	@echo "        AKEF                   ILEMAKE     FILEM   AKEFI   LEMAKEFILE      MAKEFI      "
	@echo "        LEMA                  KEFILEMA      KEF   ILEMAKEFILEMAKEFI      LEMAKE        "
	@echo "        FILEM               AKEFI LEMAK         EFILEMAKEFILEMAKEF     ILEMAKE         "
	@echo "         FILE             MAKEF  ILEMAKE         FILEMAKEFILEMAKEFIL   EMAKEFIL        "
	@echo "         EMAKE            FILEMAKEFILEMA                     KEFILEMA    KEFILEMAK     "
	@echo "          EFILE            MAKEFILEMAKE              FILE       MAKEFI  LEMA KEFIL     "
	@echo "          EMAKEF              ILEM                   AKEF        ILEMAK  EFILEMAK      "
	@echo "           EFILEM                                AKE              FILEM    AKEF        "
	@echo "            ILEMAKEF                            ILEM              AKEFI     LEMA       "
	@echo "               KEFILEM                          AKEF              ILEMAKEFILEMAK       "
	@echo "     EFI        LEMAKEFILE                       MAKE           FILEMAKEFILEMAK        "
	@echo "    EFILEMA    KEFILEMAKEFILEMAK                  EFI         LEMAKEF    I             "
	@echo "    LEMAKEFILEMAKE FILEMAKEFILEMAKEFILEM           AKEF    ILEMAKE                     "
	@echo "    FILE MAKEFILEMAKEFI    LEMAKEFILEMAKEF ILEMAKEFILEMAKEFILEMA                       "
	@echo "     KEFI  LEMAKEFILE         MAKEFILEMAK EFILEMAKEFILEMAKEFI                          "
	@echo "      LEMA   KEFILE         MAKEFILEMAKE FILEM AKEFILEMAKE                             "
	@echo "       FILEMAKEFI           LEMAKEFILEM  AKEF                                          "
	@echo "        ILEMAKE              FILEMAKE   FILE                                           "
	@echo "          MAK                EFILEM    AKEF                                            "
	@echo "                              ILEMAK  EFIL                                             "
	@echo "                               EMAKEFILEM                                              "
	@echo "                                 AKEFILE                                               "
	@echo "                                   MAK                                                 "
	@echo "\033[1;0m"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

.PHONY: clean fclean re

clean:
	@Make clean -C libft
	@echo " - Cleaning objs"
	@rm -f $(OBJS)

fclean: clean
	@Make fclean -C libft
	@echo " - Cleaning executable"
	@rm -f $(NAME)

re: fclean all
