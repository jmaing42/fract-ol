/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_get_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:29:39 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/31 02:06:11 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol_pixel	fractol_get_pixel(t_fractol *param, size_t x, size_t y)
{
	const long double			x_from_center
		= param->options->window_w * -0.5L + x;
	const long double			y_from_center
		= param->options->window_h * -0.5L + y;
	const t_fractol_position	position
		= fractol_position(
			param->center.x + x_from_center * param->size,
			param->center.y + y_from_center * param->size);

	return (fractol_get_color(param, position));
}
