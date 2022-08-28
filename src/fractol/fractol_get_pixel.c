/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_get_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:29:39 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/28 19:43:15 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	fractol_get_color_a(t_fractol *param, size_t x, size_t y)
{
	(void)param;
	(void)x;
	(void)y;
	return (1L);
}

long double	fractol_get_color_r(t_fractol *param, size_t x, size_t y)
{
	(void)param;
	(void)x;
	(void)y;
	return (1.0L / param->options->window_w * x);
}

long double	fractol_get_color_g(t_fractol *param, size_t x, size_t y)
{
	(void)param;
	(void)x;
	(void)y;
	return (1.0L / param->options->window_h * y);
}

long double	fractol_get_color_b(t_fractol *param, size_t x, size_t y)
{
	(void)param;
	(void)x;
	(void)y;
	return (1L);
}

uint32_t	fractol_get_pixel(t_fractol *param, size_t x, size_t y, int endian)
{
	t_fractol_pixel	pixel;

	if (endian)
	{
		pixel.color_big.a
			= fractol_pixel_color(fractol_get_color_a(param, x, y));
		pixel.color_big.r
			= fractol_pixel_color(fractol_get_color_r(param, x, y));
		pixel.color_big.g
			= fractol_pixel_color(fractol_get_color_g(param, x, y));
		pixel.color_big.b
			= fractol_pixel_color(fractol_get_color_b(param, x, y));
	}
	else
	{
		pixel.color_little.a
			= fractol_pixel_color(fractol_get_color_a(param, x, y));
		pixel.color_little.r
			= fractol_pixel_color(fractol_get_color_r(param, x, y));
		pixel.color_little.g
			= fractol_pixel_color(fractol_get_color_g(param, x, y));
		pixel.color_little.b
			= fractol_pixel_color(fractol_get_color_b(param, x, y));
	}
	return (pixel.pixel);
}
