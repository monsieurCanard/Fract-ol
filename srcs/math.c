/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur Canard <Monsieur Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:31:06 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/01/05 12:27:34 by Monsieur Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double nb, double min1, double max1, double max2)
{
	return ((max1 - min1) * nb / max2 + min1);
}

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

t_complex	sum_complex(t_complex z, t_complex z2)
{
	t_complex	result;

	result.real = z.real + z2.real;
	result.imaginary = z.imaginary + z2.imaginary;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.real = pow(z.real, 2) - pow(z.imaginary, 2);
	result.imaginary = 2 * z.real * z.imaginary;
	return (result);
}
