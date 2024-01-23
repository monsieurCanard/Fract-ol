/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur Canard <Monsieur Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:57:18 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/05 12:01:27 by Monsieur Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "mlx.h"

# define WIDTH 800
# define HEIGHT 800
# define ERROR_MESSAGE "Wrong arguments.\n\
---------------------\n\
You can choose between:\n\
		- Mandelbrot\n\
		- Julia\n\
		- Burningship\n\
Exemple: ./fractol Mandelbrot\n\
Exemple: ./fractol Julia\n\
---------------------\n\
TRY AGAIN !\n"

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define ORANGE 0xFFA500
# define PURPLE 0x800080
# define OR 0xFFD700
# define ORANGE_RED 0xFF4500 // Orange rougeâtre

# define ESCAPE 65307
# define SPACE 32
# define LEFT 65361
# define RIGHT 65363
# define UP 65364
# define DOWN 65362
# define PLUS 65451
# define MINUS 65453
# define ENTER 65293
# define QUIT 17

typedef struct s_complex
{
	double	real;
	double	imaginary;
}		t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;
	int		color_offset;
	int		size_line;
	int		endian;
}		t_img;

typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	char	*fractal_name;
	double	escape_value;
	int		max_iteration;
	double	shift_x;
	double	shift_y;
	double	julia_real;
	double	julia_imaginary;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}		t_fractal;

//CASE FONCTIONS
void		case_mandelbrot(t_fractal *fractal, char *str);
void		case_julia(t_fractal *fractal, char **argv, char mode);
void		case_burningship(t_fractal *fractal, char *str);

//INIT FUNCTIONS
void		init_fractal(t_fractal *fractal);
void		init_image(t_fractal *fractal);
void		data_init(t_fractal *fractal);
void		init_boundaries(t_fractal *fractal);

//MATH FONCTIONS
double		map(double nb, double min1, double max1, double max2);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z, t_complex z2);
double		ft_atoi_custom(const char *str);
double		interpolate(double start, double end, double interpolation);

//COLOR FONCTIONS
int			color_fractal(int i, t_fractal *fractal);

//CREATE FRACTAL
void		create_fractal(t_fractal *fractol);
void		handle_pixel(int x, int y, t_fractal *fractol);
void		data_init(t_fractal *fractal);
void		create_fractal(t_fractal *fractol);
void		calculate_burningship(t_fractal *fractal, int x, int y);
void		my_pixel_put(t_img *img, int x, int y, int color);

//HANDLE EVENTS FONCTIONS
int			handle_key_press(int keycode, t_fractal *fractal);
int			handle_close(t_fractal *fractal);
int			handle_mouse_press(int button, int x, int y, t_fractal *fractal);

//UTILS FONTIONS
int			ft_strncmp(const char *s1, const char *s2, size_t len);
char		*ft_tolower(char *str);
void		ft_putstr_fd(char *s, int fd);
int			verif_arg(int argc, char *argv[]);
#endif