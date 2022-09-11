/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 00:46:22 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/11 17:09:37 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_julia.h"

#include <stdlib.h>

#include "ft_types_convert_strict.h"

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
				ft_math_complex(position.x, position.y),
				((t_fractol_julia *)options->extra)->c,
				LIMIT
			),
			LIMIT
		)
	);
}

static long double	parse_if_or_default(
	bool condition,
	char *const *p_str,
	long double fallback
)
{
	long double	result;

	if (
		condition
		&& !ft_types_convert_strict_string_to_long_double(*p_str, &result)
	)
		return (result);
	return (fallback);
}

t_err	fractol_julia_init(
	t_fractol_options_get_pixel *out_get_pixel,
	t_fto_disposable **out_extra,
	size_t argc,
	char **argv
)
{
	t_fractol_julia *const	options = malloc(sizeof(t_fractol_julia));

	if (!options)
		return (true);
	options->super.v = &g_v;
	options->c
		= ft_math_complex(
			parse_if_or_default(argc > 1, &argv[1], -1.0L),
			parse_if_or_default(argc > 2, &argv[2], 0.65L));
	*out_get_pixel = &get_pixel;
	*out_extra = (t_fto_disposable *)options;
	return (false);
}
