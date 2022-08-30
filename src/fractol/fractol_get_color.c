/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_get_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 01:58:08 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/31 02:06:22 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include "fractol_mandelbrot.h"
#include "ft_math_complex.h"

#define LIMIT 800

static t_fractol_pixel	to_pixel(size_t size, size_t limit)
{
	t_fractol_pixel	result;

	result.r = 1.0L / (limit - 1) * size;
	result.g = result.r;
	result.b = result.r;
	return (result);
}

t_fractol_pixel	fractol_get_color(t_fractol *param, t_fractol_position position)
{
	(void)param;
	return (
		to_pixel(
			fractol_mandelbrot(
				ft_math_complex(position.x, position.y),
				LIMIT
			),
			LIMIT
		)
	);
}
