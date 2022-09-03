/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hooks_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:47:32 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/02 07:25:37 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_hooks.h"

#include <stdlib.h>

#include "ft_exit.h"

int	fractol_hooks_key(int keycode, t_fractol *param)
{
	(void)param;
	if (keycode == MLX_KEY_ESC)
		ft_exit(EXIT_SUCCESS);
	else if (keycode == MLX_KEY_ARROW_LEFT)
	{
		param->center.x -= 100 * param->size;
		fractol_render(param);
	}
	else if (keycode == MLX_KEY_ARROW_RIGHT)
	{
		param->center.x += 100 * param->size;
		fractol_render(param);
	}
	else if (keycode == MLX_KEY_ARROW_DOWN)
	{
		param->center.y += 100 * param->size;
		fractol_render(param);
	}
	else if (keycode == MLX_KEY_ARROW_UP)
	{
		param->center.y -= 100 * param->size;
		fractol_render(param);
	}
	return (0);
}
