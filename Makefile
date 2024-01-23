NAME = fractol

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

INC 		= 	fractol.h

SRCS		= 	main.c				\
				mandelbrot.c 		\
				julia.c 			\
				burningship.c 		\
				init_fractal.c  	\
				create_fractal.c 	\
				handle_events.c 	\
				ft_tolower.c 		\
				ft_strncmp.c 		\
				ft_putstr_fd.c 		\
				math.c 				\
			


OBJ = ${SRCS:.c=.o}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -g3 -c $< -o $@
	
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


clean:	
		rm -f *.o

fclean:	clean
		rm -f fractol 

re:	fclean all

.PHONY: re clean fclean
