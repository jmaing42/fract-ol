/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot_init.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 00:09:46 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/03 01:09:10 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_mandelbrot.h"

#include "fractol_util.h"

#define LIMIT 42

static t_fractol_pixel	get_pixel(
	t_fractol_options *options,
	t_fractol_position position
)
{
	(void)options;
	return (
		fractol_util_get_color(
			fractol_mandelbrot(
				ft_math_complex(position.x, position.y),
				LIMIT
			),
			LIMIT
		)
	);
}

t_err	fractol_mandelbrot_init(
	t_fractol_options_get_pixel *out_get_pixel,
	t_fto_disposable **out_extra,
	size_t argc,
	char **argv
)
{
	(void)argc;
	(void)argv;
	*out_get_pixel = &get_pixel;
	*out_extra = NULL;
	return (false);
}
