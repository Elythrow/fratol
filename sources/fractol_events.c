/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:00:56 by gbazin            #+#    #+#             */
/*   Updated: 2025/03/01 18:20:38 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int keycode, t_fractol *fractol)
{
	double	move_step;

	move_step = 0.1 / fractol->zoom;
	if (keycode == XK_Escape)
		clean_exit(fractol);
	else if (keycode == XK_Left)
		fractol->offset_x -= move_step;
	else if (keycode == XK_Right)
		fractol->offset_x += move_step;
	else if (keycode == XK_Up)
		fractol->offset_y -= move_step;
	else if (keycode == XK_Down)
		fractol->offset_y += move_step;
	else
		return (0);
	render_fractol(fractol);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		fractol->zoom *= 1.2;
		render_fractol(fractol);
	}
	else if (button == 5 && fractol->zoom > 0.1)
	{
		fractol->zoom /= 1.2;
		render_fractol(fractol);
	}
	return (0);
}
