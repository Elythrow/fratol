/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:42:46 by gbazin            #+#    #+#             */
/*   Updated: 2025/03/01 19:48:44 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include <math.h>
# include "mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA
}	t_fractal_type;

typedef enum e_color
{
	BLACK_WHITE,
	COLORFUL
}	t_color;

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fractol
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_fractal_type	fractal_type;
	t_color			color_scheme;
	t_complex		julia_param;
	double			zoom;
	double			offset_x;
	double			offset_y;
	int				max_iter;
}	t_fractol;

void	init_fractol(t_fractol *fractol);
int		parse_args(int argc, char **argv, t_fractol *fractol);
void	render_fractol(t_fractol *fractol);
void	draw_pixel(t_img *img, int x, int y, int color);
int		get_color(int iterations, t_color scheme);
int		calculate_mandelbrot(t_complex c, int max_iter);
int		calculate_julia(t_complex z, t_complex c, int max_iter);
int		key_handler(int keycode, t_fractol *fractol);
int		mouse_handler(int button, int x, int y, t_fractol *fractol);
int		close_window(t_fractol *fractol);
void	error_message(void);
void	clean_exit(t_fractol *fractol);

#endif