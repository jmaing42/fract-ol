/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_get_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:29:39 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/29 23:54:42 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	fractol_get_color_r(t_fractol *param, size_t x, size_t y)
{
	(void)y;
	return (1.0L / param->options->window_w * x);
}

long double	fractol_get_color_g(t_fractol *param, size_t x, size_t y)
{
	(void)x;
	return (1.0L / param->options->window_h * y);
}

long double	fractol_get_color_b(t_fractol *param, size_t x, size_t y)
{
	(void)param;
	(void)x;
	(void)y;
	return (1L);
}

t_fractol_pixel	fractol_get_pixel(t_fractol *param, size_t x, size_t y)
{
	t_fractol_pixel	result;

	result.r = fractol_get_color_r(param, x, y);
	result.g = fractol_get_color_g(param, x, y);
	result.b = fractol_get_color_b(param, x, y);
	return (result);
}
