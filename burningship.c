/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur Canard <Monsieur Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:01:56 by Monsieur Ca       #+#    #+#             */
/*   Updated: 2024/01/05 11:11:38 by Monsieur Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	open_menu(void)
{
	printf("\n!!!!!! Welcome to the BurningShip fractal !!!!!!\n");
	printf("---------------------------------------------------\n");
	printf("You can use the following keys:\n");
	printf("---------------------------------------------------\n");
	printf("ESC to quit the program.\n");
	printf("PLUS to increase the number of iterations.\n");
	printf("MINUS to decrease the number of iterations.\n");
	printf("LEFT to move the fractal to the left.\n");
	printf("RIGHT to move the fractal to the right.\n");
	printf("UP to move the fractal up.\n");
	printf("DOWN to move the fractal down.\n");
	printf("MOUSE WHEEL UP to zoom in.\n");
	printf("MOUSE WHEEL DOWN to zoom out.\n");
	printf("SPACE to change the color.\n");
	printf("---------------------------------------------------\n");
	printf("Have fun!\n");
}

void	case_burningship(t_fractal *fractal, char *str)
{
	fractal->fractal_name = str;
	open_menu();
	init_fractal(fractal);
	create_fractal(fractal);
	mlx_key_hook(fractal->win_ptr, handle_key_press, fractal);
	mlx_hook(fractal->win_ptr, 17, 0, handle_close, fractal);
	mlx_mouse_hook(fractal->win_ptr, handle_mouse_press, fractal);
	mlx_loop(fractal->mlx_ptr);
}

void	calculate_burningship(t_fractal *fractal, int x, int y)
{
	t_complex	c;
	t_complex	z;
	double		tmp;
	int			i;

	i = -1;
	c.real = (double)x / (WIDTH / (fractal->x_max - fractal->x_min))
		+ fractal->x_min + fractal->shift_x;
	c.imaginary = (double)y / (HEIGHT / (fractal->y_max - fractal->y_min))
		+ fractal->y_min + fractal->shift_y;
	z.real = 0;
	z.imaginary = 0;
	while (++i < fractal->max_iteration)
	{
		tmp = z.real * z.real - z.imaginary * z.imaginary + c.real;
		z.imaginary = 2.0 * fabs(z.real * z.imaginary) + c.imaginary;
		z.real = tmp;
		if (z.real * z.real + z.imaginary * z.imaginary > fractal->escape_value)
		{
			my_pixel_put(&fractal->img, x, y, color_fractal(i, fractal));
			return ;
		}
	}
	my_pixel_put(&fractal->img, x, y, BLACK);
}
