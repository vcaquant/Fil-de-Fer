# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/15 16:05:38 by vcaquant          #+#    #+#              #
#    Updated: 2016/11/15 16:05:40 by vcaquant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			fdf

SRC = 			sources/fdf.c \
						sources/ft_code.c \
						sources/ft_help.c \
						sources/ft_bressenham.c \
						sources/ft_recup.c \
						sources/ft_error.c \
						sources/drawline.c \
						sources/drawline_beeline.c \
						sources/drawline_cadran.c \
						sources/drawline_cadran2.c \
						sources/ft_ex.c \
						sources/ft_ex_end.c \
						sources/ft_color.c


OBJ = 			fdf.o \
						ft_code.o \
						ft_help.o \
						ft_bressenham.o \
						ft_recup.o \
						ft_error.o \
						drawline.o \
						drawline_beeline.o \
						drawline_cadran.o \
						drawline_cadran2.o \
						ft_ex.o \
						ft_ex_end.o \
						ft_color.o

HEADER =		./libft/libft.h\

FINDLIBFT =	-Llibft

PT_A =			./minilibx_macos/libmlx.a \
			./libft/libft.a

FLAGS = 		-Wall -Wextra -Werror -g

LIBX_FS =		-framework OpenGL -framework AppKit

LIBFT_DIR =	./libft/

LIBX_DIR =	./minilibx_macos/

CC = 				gcc

all:	comp_oth $(NAME)

comp_oth:
		@make fclean -C $(LIBFT_DIR)
		@make -C $(LIBFT_DIR)
		@make -C $(LIBX_DIR)

$(NAME):
		@clear
		@$(CC) $(FLAGS) -c $(SRC) $(HEADER)
		@$(CC) -o $(NAME) $(OBJ) $(PT_A) $(LIBX_FS)
		@echo "\033[0;32m✔︎ Compilation Done\033[0m"

clean:
		@clear
		@rm -f $(OBJ)
		@rm -f fdf.h.gch
		@make clean -C $(LIBFT_DIR)
		@make clean -C $(LIBX_DIR)

fclean:	clean
		@clear
		@rm -f $(NAME)
		@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all, clean, fclean, re
