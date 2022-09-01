/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hooks_mouse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:50:46 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/01 22:53:29 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_hooks.h"

int	fractol_hooks_mouse(int button, int x, int y, t_fractol *param)
{
	(void)x;
	(void)y;
	if (button == MLX_BUTTON_SCROLL_UP)
	{
		param->size *= 1.1;
		fractol_render(param);
	}
	else if (button == MLX_BUTTON_SCROLL_DOWN)
	{
		param->size /= 1.1;
		fractol_render(param);
	}
	else if (button == MLX_BUTTON_LEFT)
	{
		param->center.x
			+= (x - param->options->window_w / 2.0L) * param->size;
		param->center.y
			+= (y - param->options->window_h / 2.0L) * param->size;
		fractol_render(param);
	}
	return (0);
}
