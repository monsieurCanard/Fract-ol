/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractale_mandelbrot_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:12:56 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2023/12/11 18:46:34 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse_click_mandelbrot(int button, int x, int y, t_fractol *ptr)
{
	if (button == 4)
	{
		ptr->zoom *= 0.9;
	}
	else if (button == 5)
	{
		ptr->zoom *= 1.1;
	}
	ptr->zx = ptr->zx + ((double)x - 500) / (ptr->zoom * ptr->zoom_level);
	ptr->zy = ptr->zy + ((double)y - 500) / (ptr->zoom * ptr->zoom_level);
	mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
	fractale_mandelbrot(ptr);
	printf("button: %d, x: %d, y: %d\n", button, x, y);
	return (0);
}

int	handle_key_press_mandelbrot(int keycode, t_fractol *ptr)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
		exit(0);
	}
	else if (keycode == 65364)
		ptr->zoom_level /= 1.1;
	else if (keycode == 65362)
		ptr->zoom_level *= 1.1;
	else if (keycode == 65361)
		ptr->zx -= 7 / (ptr->zoom * ptr->zoom_level);
	else if (keycode == 65363)
		ptr->zx += 7 / (ptr->zoom * ptr->zoom_level);
	else if (keycode == 65365)
		ptr->zy -= 0.1 / (ptr->zoom * ptr->zoom_level);
	else if (keycode == 65366)
		ptr->zy += 0.1 / (ptr->zoom * ptr->zoom_level);
	else if (keycode == 114)
		ptr->red = (ptr->red + 10) % 256;
	else if (keycode == 118)
		ptr->green = (ptr->green + 10) % 256;
	else if (keycode == 98)
		ptr->blue = (ptr->blue + 10) % 256;
	mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
	fractale_mandelbrot(ptr);
	return (0);
}
