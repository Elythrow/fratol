/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_calcul.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:59:02 by gbazin            #+#    #+#             */
/*   Updated: 2025/03/01 18:20:37 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include "fractol.h"

int	calculate_mandelbrot(t_complex c, int max_iter)
{
	t_complex	z;
	double		temp;
	int			i;

	z.real = 0.0;
	z.imag = 0.0;
	i = 0;
	while (i < max_iter)
	{
		if ((z.real * z.real + z.imag * z.imag) > 4.0)
			break ;
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = temp;
		i ++;
	}
	return (i);
}

int	calculate_julia(t_complex z, t_complex c, int max_iter)
{
	double	temp;
	int		i;

	i = 0;
	while (i < max_iter)
	{
		if ((z.real * z.real + z.imag * z.imag) > 4.0)
			break ;
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = temp;
		i ++;
	}
	return (i);
}
