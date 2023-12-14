/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:12:14 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2023/12/11 18:52:33 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>


typedef struct s_fractol
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;
	int		max_i;
	int		x;
	int		y;
	double	zoom;
	double	zx;
	double	zy;
	double	tmp;
	double	x_tmp;
	int		co;
	double	mouse_x;
	double	mouse_y;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double 	cx;
	double	cy;
	double	zoom_level;
	int		red;
	int		green;
	int		blue;
	double	reel;
	double	imaginaire;
}				t_fractol;

//Fractale Julia
int fractale_julia(t_fractol *ptr);
void	run_fractale_julia(int mode);
int	handle_key_press(int keycode, t_fractol *ptr);
int	handle_mouse_click(int button, int x, int y, t_fractol *ptr);
void	case_julia(void);


//Fractale Mandelbrot
void	run_fractale_mandelbrot(int mode);
int	handle_key_press_mandelbrot(int keycode, t_fractol *ptr);
int	handle_mouse_click_mandelbrot(int button, int x, int y, t_fractol *ptr);
void	case_mandelbrot(void);
int	fractale_mandelbrot(t_fractol *ptr);


int	ft_strncmp(const char *s1, const char *s2, size_t len);
int	handle_key_press_intermediate(int keycode, void *param);
int	handle_key_press(int keycode, t_fractol *ptr);
void	draw_circle(void *mlx_ptr, void *win_ptr, int x, int y, int radius, int color);

#endif