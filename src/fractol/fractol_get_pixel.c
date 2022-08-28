/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_get_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:29:39 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/28 17:40:50 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	fractol_get_pixel(t_fractol *param, size_t x, size_t y)
{
	t_fractol_pixel	pixel;

	pixel.color.a = fractol_pixel_color(1);
	pixel.color.r = fractol_pixel_color(1.0 / param->options->window_w * x);
	pixel.color.g = fractol_pixel_color(1.0 / param->options->window_h * y);
	pixel.color.b = fractol_pixel_color(0);
	return (pixel.pixel);
}
