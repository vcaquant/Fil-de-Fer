NAME = 			fdf

SRC = 			fdf.c \
						ft_code.c \
						ft_bressenham.c \
						ft_recup.c \
						ft_error.c

OBJ = 			fdf.o \
						ft_code.o \
						ft_bressenham.o \
						ft_recup.o \
						ft_error.o

HEADER =		./libft/libft.h\

FINDLIBFT =	-Llibft

PT_A =			./minilibx_macos/libmlx.a \
			./libft/libft.a

FLAGS = 		-Wall -Wextra -Werror

LIBX_FS =		-framework OpenGL -framework AppKit

LIBFT_DIR =	./libft/

LIBX_DIR =	./minilibx_macos/

CC = 				gcc

all:	comp_oth $(NAME)

comp_oth:
		make fclean -C $(LIBFT_DIR)
		make -C $(LIBFT_DIR)
		make -C $(LIBX_DIR)

$(NAME):
		@clear
		$(CC) $(FLAGS) -c $(SRC) $(HEADER)
		$(CC) -o $(NAME) $(OBJ) $(PT_A) $(LIBX_FS) -g

clean:
		@clear
		rm -f $(OBJ)
		rm -f fdf.h.gch
		make clean -C $(LIBFT_DIR)
		make clean -C $(LIBX_DIR)

fclean:	clean
		@clear
		rm -f $(NAME)
		make fclean -C $(LIBFT_DIR)

re: fclean all
		@clear

.PHONY: all, clean, fclean, re
