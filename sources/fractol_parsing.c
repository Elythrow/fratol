/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:47:53 by gbazin            #+#    #+#             */
/*   Updated: 2025/03/01 19:31:34 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include "fractol.h"

void	error_message(void)
{
	ft_putstr_fd("Invalid Arguments\n", 1);
	ft_putstr_fd("Usage\n", 1);
	ft_putstr_fd("./fractol Julia [R_Part] [I_Part] [color: bw/color]\n", 1);
	ft_putstr_fd("./fractol Mandelbrot [color: bw/color]\n", 1);
}

static int	check_double(char *str)
{
	int	i;
	int	dot_count;

	i = 0;
	dot_count = 0;
	if (str[i] == '-' || str[i] == '+')
		i ++;
	while (str[i])
	{
		if (str[i] == '.')
			dot_count ++;
		else if (!ft_isdigit(str[i]))
			return (0);
		i ++;
	}
	return (dot_count <= 1);
}

static int	parse_julia_args(int argc, char **argv, t_fractol *fractol)
{
	if (argc < 4)
		return (0);
	if (!check_double(argv[2]) || !check_double(argv[3]))
		return (0);
	fractol->julia_param.real = ft_atod(argv[2]);
	fractol->julia_param.imag = ft_atod(argv[3]);
	fractol->fractal_type = JULIA;
	if (argc >= 5 && ft_strncmp(argv[4], "bw", 3) == 0)
		fractol->color_scheme = BLACK_WHITE;
	else
		fractol->color_scheme = COLORFUL;
	return (1);
}

static int	parse_mandelbrot_args(int argc, char **argv, t_fractol *fractol)
{
	fractol->fractal_type = MANDELBROT;
	if (argc >= 3 && ft_strncmp(argv[2], "bw", 3) == 0)
		fractol->color_scheme = BLACK_WHITE;
	else
		fractol->color_scheme = COLORFUL;
	return (1);
}

int	parse_args(int argc, char **argv, t_fractol *fractol)
{
	if (argc < 2)
		return (0);
	if (ft_strncmp(argv[1], "Julia", 6) == 0)
		return (parse_julia_args(argc, argv, fractol));
	else if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
		return (parse_mandelbrot_args(argc, argv, fractol));
	return (0);
}
