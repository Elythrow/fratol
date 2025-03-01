/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:00:06 by gbazin            #+#    #+#             */
/*   Updated: 2025/03/01 19:49:35 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(int *)pixel = color;
	}
}

int	get_color(int iterations, t_color scheme)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iterations == MAX_ITER)
		return (0);
	t = (double)iterations / MAX_ITER;
	if (scheme == BLACK_WHITE)
	{
		r = (int)(255.0 * t);
		g = (int)(255.0 * t);
		b = (int)(255.0 * t);
	}
	else
	{
		r = (int)(9.0 * (1.0 - t) * t * t * t * 255.0);
		g = (int)(15.0 * (1.0 - t) * (1.0 - t) * t * t * 255.0);
		b = (int)(8.5 * (1.0 - t) * (1.0 - t) * (1.0 - t) * t * 255.0);
	}
	return ((r << 16) | (g << 8) | b);
}

static void	calculate_pixel(t_fractol *fractol, int x, int y)
{
	t_complex	c;
	t_complex	z;
	int			i;
	int			color;

	c.real = (x - WIDTH / 2.0) / (0.5 * WIDTH * fractol->zoom)
		+ fractol->offset_x;
	c.imag = (y - HEIGHT / 2.0) / (0.5 * HEIGHT * fractol->zoom)
		+ fractol->offset_y;
	if (fractol->fractal_type == MANDELBROT)
		i = calculate_mandelbrot(c, fractol->max_iter);
	else
	{
		z = c;
		i = calculate_julia(z, fractol->julia_param, fractol->max_iter);
	}
	color = get_color(i, fractol->color_scheme);
	draw_pixel(&fractol->img, x, y, color);
}

void	render_fractol(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			calculate_pixel(fractol, x, y);
			x ++;
		}
		y ++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->img.img_ptr, 0, 0);
}
