/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:47:27 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/10/07 12:46:43 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char *argv[])
{
	t_fractal fractal;
	char mode[1];
	ssize_t ret;

	if (verif_arg(argc, argv) == 1)
	{
		if (ft_strncmp(ft_tolower(argv[1]), "mandelbrot", 10) == 0)
			case_mandelbrot(&fractal, argv[1]);
		else if (ft_strncmp(ft_tolower(argv[1]), "julia", 5) == 0)
		{
			printf("Choose a number:(between 1 and 4)\n");
			printf("---------------------------------------------------\n");
			ret = read(0, mode, 1);
			(void)ret;
			case_julia(&fractal, argv, mode[0]);
		}
		else if (ft_strncmp(ft_tolower(argv[1]), "burningship", 11) == 0)
			case_burningship(&fractal, argv[1]);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int verif_arg(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (ft_strncmp(ft_tolower(argv[1]), "mandelbrot", 10) == 0)
			return (1);
		else if (ft_strncmp(ft_tolower(argv[1]), "julia", 5) == 0)
			return (1);
		else if (ft_strncmp(ft_tolower(argv[1]), "burningship", 11) == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
