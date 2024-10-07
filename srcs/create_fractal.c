/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur Canard <Monsieur Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:25:31 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/05 13:08:46 by Monsieur Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int		offset;

	offset = (y * img->size_line) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

int	color_fractal(int i, t_fractal *fractol)
{
	int		red;
	int		green;
	int		blue;
	double	smooth_i;

	smooth_i = i - 1 - log(i) / log(2);
	red = sin(smooth_i * 0.1) * 128 + fractol->img.color_offset;
	green = cos(smooth_i * 0.2) * 128 + fractol->img.color_offset;
	blue = sin(smooth_i * 0.3) * cos(smooth_i * 0.4)
		* 128 + fractol->img.color_offset;
	return ((red << 16) | (green << 8) | blue);
}

static void	handle_fractal(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (ft_strncmp(ft_tolower(fractal->fractal_name), "mandelbrot", 10) == 0)
	{
		c->real = z->real;
		c->imaginary = z->imaginary;
	}
	else
	{
		c->real = fractal->julia_real;
		c->imaginary = fractal->julia_imaginary;
	}
}

void	handle_pixel(int x, int y, t_fractal *fractol)
{
	t_complex	c;
	t_complex	z;
	int			i;
	int			color;

	color = 0;
	i = 0;
	z.real = map(x, fractol->x_min, fractol->x_max, WIDTH)
		+ fractol->shift_x;
	z.imaginary = map(y, fractol->y_min, fractol->y_max, HEIGHT)
		+ fractol->shift_y ;
	handle_fractal(&z, &c, fractol);
	while (i < fractol->max_iteration)
	{
		z = sum_complex(square_complex(z), c);
		if (z.real * z.real + z.imaginary * z.imaginary > fractol->escape_value)
		{
			color = color_fractal(i, fractol);
			my_pixel_put(&fractol->img, x, y, color);
			return ;
		}
		i++;
	}
	my_pixel_put(&fractol->img, x, y, BLACK);
}

void	create_fractal(t_fractal *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (ft_strncmp(fractol->fractal_name, "burningship", 11) == 0)
				calculate_burningship(fractol, x, y);
			else
				handle_pixel (x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img.img_ptr, 0, 0);
}
