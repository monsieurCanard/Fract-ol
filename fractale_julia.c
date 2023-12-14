/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractale_julia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:43:05 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2023/12/12 11:26:36 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_fractale_julia(t_fractol *ptr)
{
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, 1000, 1000, "Fractale Julia");
	ptr->zoom = 1000.0;
	ptr->zoom_level = 1.0;
	mlx_key_hook(ptr->win_ptr, handle_key_press, ptr);
	mlx_mouse_hook(ptr->win_ptr, handle_mouse_click, ptr);
}

void	calcul_fractale_julia(t_fractol *ptr)
{
	double	zx;
	double	zy;
	int		red;
	int		green;
	int		blue;

	zx = ptr->zx + (ptr->x - 500) / (ptr->zoom * ptr->zoom_level);
	zy = ptr->zy + (ptr->y - 500) / (ptr->zoom * ptr->zoom_level);
	ptr->i = 0;
	ptr->max_i = 377;
	while (zx * zx + zy * zy < 4 && ptr->i < ptr->max_i)
	{
		ptr->x_tmp = zx * zx - zy * zy + ptr->reel;
		zy = 2 * zx * zy + ptr->imaginaire;
		zx = ptr->x_tmp;
		ptr->i++;
	}
	red = ptr->red + sin(ptr->i * 0.1) * 128;
	green = ptr->green + cos(ptr->i * 0.2) * 128;
	blue = ptr->blue + sin(ptr->i * 0.3) * cos(ptr->i * 0.4) * 128;
	ptr->co = (red << 16) | (green << 8) | blue;
}

int	fractale_julia(t_fractol *ptr)
{
	mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
	if (!ptr->mlx_ptr || !ptr->win_ptr)
		return (0);
	ptr->x = 0;
	while (ptr->x < 1000)
	{
		ptr->y = 0;
		while (ptr->y < 1000)
		{
			calcul_fractale_julia(ptr);
			mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr, ptr->x, ptr->y, ptr->co);
			ptr->y++;
		}
		ptr->x++;
	}
	mlx_loop(ptr->mlx_ptr);
	return (0);
}

void	run_fractale_julia(int mode)
{
	t_fractol	ptr;

	initialize_fractale_julia(&ptr);
	if (mode == 1)
	{
		ptr.reel = -1.417022285618;
		ptr.imaginaire = 0.0099534;
	}
	else if (mode == 2)
	{
		ptr.reel = -0.8;
		ptr.imaginaire = 0.156;
	}
	else if (mode == 3)
	{
		ptr.reel = -0.038088;
		ptr.imaginaire = 0.9754633;
	}
	else if (mode == 4)
	{
		ptr.reel = 0.285;
		ptr.imaginaire = 0.013;
	}
	fractale_julia(&ptr);
}
