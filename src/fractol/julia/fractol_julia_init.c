/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 00:46:22 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/03 01:27:42 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_julia.h"

#include <stdlib.h>

#include "fractol_util.h"

#define LIMIT 80

static void	dispose(t_fractol_julia *self)
{
	free(self);
}

static const t_fto_disposable_vtable	g_v = {
	(t_fto_disposable_v_dispose)dispose,
};

static t_fractol_pixel	get_pixel(
	t_fractol_options *options,
	t_fractol_position position
)
{
	return (
		fractol_util_get_color(
			fractol_julia(
				((t_fractol_julia *)options->extra)->z,
				ft_math_complex(position.x, position.y),
				LIMIT
			),
			LIMIT
		)
	);
}

t_err	fractol_julia_init(
	t_fractol_options_get_pixel *out_get_pixel,
	t_fto_disposable **out_extra,
	size_t argc,
	char **argv
)
{
	t_fractol_julia *const	options = malloc(sizeof(t_fractol_julia));

	(void)argc;
	(void)argv;
	if (!options)
		return (true);
	options->super.v = &g_v;
	options->z = ft_math_complex(-1.0L, 0.65L);
	*out_get_pixel = &get_pixel;
	*out_extra = (t_fto_disposable *)options;
	return (false);
}
