NAME = fractol

CC = cc

CFLAGS = -Wall -Werror -Wextra

INC 		= 	mlx.h

SRCS		= 	main.c		\
				fractale_julia.c \
				fractale_julia_utils.c \
				fractale_mandelbrot.c \
				fractale_mandelbrot_utils.c \
				ft_strncmp.c \
						


OBJ = ${SRCS:.c=.o}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
	
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:	
		rm -f *.o

fclean:	clean
		rm -f fractol 

re:	fclean all

.PHONY: re clean fclean
