/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur Canard <Monsieur Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:01:39 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/05 17:19:06 by Monsieur Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (fractal->mlx_ptr == NULL)
	{
		ft_putstr_fd("Error while initialising mlx_ptr.\n", 1);
		exit (EXIT_FAILURE);
	}
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr,
			WIDTH, HEIGHT, fractal->fractal_name);
	if (fractal->win_ptr == NULL)
	{
		ft_putstr_fd("Error while initialising mlx_win.\n", 1);
		mlx_destroy_display(fractal->mlx_ptr);
		free (fractal->mlx_ptr);
		exit (EXIT_FAILURE);
	}
	init_image(fractal);
	data_init(fractal);
}

void	init_image(t_fractal *fractal)
{
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		ft_putstr_fd("Error while initialising new_image.\n", 1);
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		mlx_destroy_display(fractal->mlx_ptr);
		free (fractal->mlx_ptr);
		exit (EXIT_FAILURE);
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.size_line, &fractal->img.endian);
}

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->max_iteration = 100;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	init_boundaries(fractal);
	fractal->img.color_offset = 1;
}

void	init_boundaries(t_fractal *fractal)
{
	if (fractal->fractal_name[0] == 'm')
	{
		fractal->x_max = 0.47;
		fractal->x_min = -2.0;
		fractal->y_min = -1.12;
		fractal->y_max = (fractal->x_max - fractal->x_min) * HEIGHT / WIDTH
			+ fractal->y_min;
	}
	else if (fractal->fractal_name[0] == 'j')
	{
		fractal->x_max = 1.0;
		fractal->x_min = -1.0;
		fractal->y_min = -1.0;
		fractal->y_max = (fractal->x_max - fractal->x_min) * HEIGHT / WIDTH
			+ fractal->y_min;
	}
	else if (fractal->fractal_name[0] == 'b')
	{
		fractal->x_max = 0.47;
		fractal->x_min = -2.0;
		fractal->y_min = -1.12;
		fractal->y_max = (fractal->x_max - fractal->x_min) * HEIGHT / WIDTH
			+ fractal->y_min;
	}
}
