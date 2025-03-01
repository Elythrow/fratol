/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:05:21 by gbazin            #+#    #+#             */
/*   Updated: 2025/03/01 18:20:39 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (!parse_args(argc, argv, &fractol))
	{
		error_message();
		return (EXIT_FAILURE);
	}
	init_fractol(&fractol);
	render_fractol(&fractol);
	mlx_hook(fractol.win, KeyPress, KeyPressMask, key_handler, &fractol);
	mlx_hook(fractol.win, ButtonPress, ButtonPressMask, mouse_handler, &fractol);
	mlx_hook(fractol.win, DestroyNotify, StructureNotifyMask,
		close_window, &fractol);
	mlx_loop(fractol.mlx);
	return (EXIT_SUCCESS);
}
