/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init_options.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 01:02:16 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/03 01:12:23 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include "fractol_julia.h"

static t_err	init_rest(t_fractol_options *out, size_t argc, char **argv)
{
	return (fractol_julia_init(&out->get_pixel, &out->extra, argc, argv));
}

t_err	fractol_init_options(t_fractol_options *out, size_t argc, char **argv)
{
	out->title = argv[0];
	out->window_w = 640;
	out->window_h = 480;
	return (init_rest(out, argc + 1, argv + 1));
}
