/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur Canard <Monsieur Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:26:58 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/05 10:34:25 by Monsieur Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	open_menu(void)
{
	printf("!!!!Welcome to the Mandelbrot fractal.!!!!\n");
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

void	case_mandelbrot(t_fractal *fractal, char *str)
{
	open_menu();
	fractal->fractal_name = str;
	init_fractal(fractal);
	create_fractal(fractal);
	mlx_key_hook(fractal->win_ptr, handle_key_press, fractal);
	mlx_hook(fractal->win_ptr, 17, 0, handle_close, fractal);
	mlx_mouse_hook(fractal->win_ptr, handle_mouse_press, fractal);
	mlx_loop(fractal->mlx_ptr);
}
