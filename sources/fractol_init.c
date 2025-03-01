/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:58:32 by gbazin            #+#    #+#             */
/*   Updated: 2025/03/01 18:20:38 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_default_values(t_fractol *fractol)
{
	fractol->zoom = 1.0;
	fractol->offset_x = 0.0;
	fractol->offset_y = 0.0;
	fractol->max_iter = MAX_ITER;
}

static void	init_img(t_fractol *fractol)
{
	fractol->img.img_ptr = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->img.img_ptr)
		clean_exit(fractol);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bpp, &fractol->img.line_len, &fractol->img.endian);
	if (!fractol->img.addr)
		clean_exit(fractol);
}

void	init_fractol(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		exit(EXIT_FAILURE);
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Fractol");
	if (!fractol->win)
	{
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		exit(EXIT_FAILURE);
	}
	init_img(fractol);
	init_default_values(fractol);
}

void	clean_exit(t_fractol *fractol)
{
	if (fractol->img.img_ptr)
		mlx_destroy_image(fractol->mlx, fractol->img.img_ptr);
	if (fractol->win)
		mlx_destroy_window(fractol->mlx, fractol->win);
	if (fractol->mlx)
	{
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
	}
	exit(EXIT_SUCCESS);
}

int	close_window(t_fractol *fractol)
{
	clean_exit(fractol);
	return (0);
}
