/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot_init.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 00:09:46 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/03 00:34:44 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_mandelbrot.h"

#include <stdlib.h>

static void	dispose(t_fractol_mandelbrot *self)
{
	free(self);
}

static const t_fto_disposable_vtable	g_v = {
	(t_fto_disposable_v_dispose)dispose,
};

t_err	fractol_mandelbrot_init(
	t_fractol_options_get_pixel *out_get_pixel,
	t_fto_disposable *out_extra,
	size_t argc,
	char **argv
)
{
	(void)argc;
	(void)argv;
	*out_get_pixel = get_pixel;
	*out_extra = NULL;
	return (false);
}
