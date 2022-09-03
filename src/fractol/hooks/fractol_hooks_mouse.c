/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hooks_mouse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:50:46 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/02 00:52:28 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_hooks.h"

static void	zoom(t_fractol *param, long double factor, int x, int y)
{
	const long double			new_distance_x
		= (x - param->options->window_w / 2.0L) * factor;
	const long double			new_distance_y
		= (y - param->options->window_h / 2.0L) * factor;
	const long double			clicked_x
		= param->center.x + (x - param->options->window_w / 2.0L) * param->size;
	const long double			clicked_y
		= param->center.y + (y - param->options->window_h / 2.0L) * param->size;
	const t_fractol_position	new_center = {
		clicked_x - new_distance_x * param->size,
		clicked_y - new_distance_y * param->size,
	};

	param->size *= factor;
	param->center = new_center;
}

int	fractol_hooks_mouse(int button, int x, int y, t_fractol *param)
{
	(void)x;
	(void)y;
	if (button == MLX_BUTTON_SCROLL_UP)
	{
		zoom(param, 1.1L, x, y);
		fractol_render(param);
	}
	else if (button == MLX_BUTTON_SCROLL_DOWN)
	{
		zoom(param, 1.0L / 1.1L, x, y);
		fractol_render(param);
	}
	return (0);
}
