/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur Canard <Monsieur Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:34:47 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/05 17:07:54 by Monsieur Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_choice(t_fractal *fractal, char mode)
{
	if (mode - 48 == 1)
	{
		fractal->julia_real = 0.3;
		fractal->julia_imaginary = 0.5;
	}
	else if (mode - 48 == 2)
	{
		fractal->julia_real = 0.285;
		fractal->julia_imaginary = 0.01;
	}
	else if (mode - 48 == 3)
	{
		fractal->julia_real = -0.8;
		fractal->julia_imaginary = 0.156;
	}
	else if (mode - 48 == 4)
	{
		fractal->julia_real = -1.417022285618;
		fractal->julia_imaginary = 0.0099534;
	}
	else
	{
		fractal->julia_real = -0.4;
		fractal->julia_imaginary = 0.6;
	}
}

static void	open_menu(void)
{
	printf("!!!!!! Welcome to the Julia fractal !!!!!!\n");
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

void	case_julia(t_fractal *fractal, char **argv, char mode)
{
	fractal->fractal_name = argv[1];
	handle_choice(fractal, mode);
	open_menu();
	init_fractal(fractal);
	create_fractal(fractal);
	mlx_key_hook(fractal->win_ptr, handle_key_press, fractal);
	mlx_hook(fractal->win_ptr, 17, 0, handle_close, fractal);
	mlx_mouse_hook(fractal->win_ptr, handle_mouse_press, fractal);
	mlx_loop(fractal->mlx_ptr);
}
