/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:37:19 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2023/12/11 18:51:56 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Wrong answer !!!!!\n");
		printf("You can ONLY draw this fractals : \n1 - Mandelbrot\n2 - Julia\n");
		printf("I let you try again !\n");
		exit (0);
	}
	if (ft_strncmp(argv[1], "Julia", 5) == 0)
		case_julia();
	else if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
		case_mandelbrot();
	else
	{
		printf("I don't know this fractal !\n");
		printf("You can draw this fractals : \n1 - Mandelbrot\n2 - Julia\n");
		printf("Try again !\n");
	}
	return (0);
}

void	case_julia(void)
{
	char	str_mode[2];
	int		index;

	index = 0;
	printf("You choose Julia !\nYou have 4 different Julia fractals :\n");
	printf("Witch one do you want to draw ?(enter the number)\n");
	index = read(0, str_mode, 100);
	str_mode[index - 1] = '\0';
	run_fractale_julia(str_mode[0] - 48);
}

void	case_mandelbrot(void)
{
	char	str_mode[2];
	int		index;

	index = 0;
	printf("You choose Mandelbrot !\nYou have 4 different Mandelbrot fractals :\n");
	printf("Witch one do you want to draw ?(enter the number)\n");
	index = read(0, str_mode, 100);
	str_mode[index - 1] = '\0';
	run_fractale_mandelbrot(str_mode[0] - 48);
}