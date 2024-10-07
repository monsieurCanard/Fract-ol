/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur Canard <Monsieur Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:42:46 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/05 17:20:40 by Monsieur Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key_press(int keycode, t_fractal *fractal)
{
	if (keycode == ESCAPE)
		handle_close(fractal);
	else if (keycode == PLUS)
		fractal->max_iteration += 100;
	else if (keycode == MINUS)
		fractal->max_iteration -= 100;
	else if (keycode == LEFT)
		fractal->shift_x += 0.5 * (fractal->x_max - fractal->x_min) / 10;
	else if (keycode == RIGHT)
		fractal->shift_x -= 0.5 * (fractal->x_max - fractal->x_min) / 10;
	else if (keycode == UP)
		fractal->shift_y += 0.5 * (fractal->y_max - fractal->y_min) / 10;
	else if (keycode == DOWN)
		fractal->shift_y -= 0.5 * (fractal->y_max - fractal->y_min) / 10;
	else if (keycode == SPACE)
		fractal->img.color_offset += 17;
	create_fractal(fractal);
	return (0);
}

int	handle_close(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	mlx_destroy_image(fractal->mlx_ptr, fractal->img.img_ptr);
	mlx_destroy_display(fractal->mlx_ptr);
	free (fractal->mlx_ptr);
	exit (EXIT_SUCCESS);
	return (0);
}

static void	applyzoom(t_fractal *fractal, double zoom, double mouse_re,
		double mouse_im)
{
	double	interpolation;

	interpolation = 1.0 / zoom;
	fractal->x_min = interpolate(mouse_re, fractal->x_min, interpolation);
	fractal->x_max = interpolate(mouse_re, fractal->x_max, interpolation);
	fractal->y_min = interpolate(mouse_im, fractal->y_min, interpolation);
	fractal->y_max = interpolate(mouse_im, fractal->y_max, interpolation);
}

int	handle_mouse_press(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = (double)x / (WIDTH / (fractal->x_max - fractal->x_min))
		+ fractal->x_min;
	mouse_im = (double)y / (HEIGHT / (fractal->y_max - fractal->y_min))
		+ fractal->y_min;
	if (button == 4)
	{
		applyzoom(fractal, 1.1, mouse_re, mouse_im);
		fractal->max_iteration += 5;
	}
	else if (button == 5)
	{
		applyzoom(fractal, 0.9, mouse_re, mouse_im);
		fractal->max_iteration -= 5;
	}
	create_fractal(fractal);
	return (0);
}
