/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:29:18 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/01 22:52:57 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdlib.h>
#include <limits.h>
#include <mlx.h>

#include "ft_exit.h"
#include "ft_assert.h"

#include "fractol_hooks.h"

t_err	fractol_init_options(t_fractol_options *out)
{
	out->title = "fract-ol";
	out->window_w = 640;
	out->window_h = 480;
	return (false);
}

t_err	fractol_init(t_fractol *out, t_fractol_options *options)
{
	out->options = options;
	out->mlx_context = mlx_init();
	if (
		!out->mlx_context
		|| options->window_h > INT_MAX
		|| options->window_w > INT_MAX
	)
		return (true);
	out->mlx_window = ft_assert_nonnull(mlx_new_window(
				out->mlx_context,
				options->window_w,
				options->window_h,
				options->title));
	out->image = ft_assert_nonnull(mlx_new_image(
				out->mlx_context,
				options->window_w,
				options->window_h));
	mlx_hook(out->mlx_window, MLX_EVENT_ON_DESTROY, 0, &fractol_hooks_exit, 0);
	mlx_hook(out->mlx_window, MLX_EVENT_ON_KEYDOWN, 0, &fractol_hooks_key, out);
	mlx_hook(out->mlx_window, MLX_EVENT_ON_MOUSE, 0, &fractol_hooks_mouse, out);
	out->center = fractol_position(0.0L, 0.0L);
	out->size = 4.2L / options->window_w;
	return (false);
}
