/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:29:18 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/28 17:29:19 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdlib.h>
#include <limits.h>
#include <mlx.h>

#include "ft_exit.h"
#include "ft_assert.h"

#define MLX_EVENT_ON_KEYDOWN 2
#define MLX_EVENT_ON_KEYUP 3
#define MLX_EVENT_ON_DESTROY 17

#define KEY_ESC 53
#define KEY_Q 12
#define KEY_W 13
#define KEY_E 14
#define KEY_R 15
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

static int	key_press(int keycode, t_fractol *param)
{
	(void)param;
	if (keycode == KEY_ESC)
		ft_exit(EXIT_SUCCESS);
	fractol_render(param);
	return (0);
}

static int	fractol_exit(int unused, void *param)
{
	(void)unused;
	(void)param;
	ft_exit(EXIT_SUCCESS);
	return (0);
}

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
	mlx_hook(out->mlx_window, MLX_EVENT_ON_KEYDOWN, 0, &key_press, out);
	mlx_hook(out->mlx_window, MLX_EVENT_ON_DESTROY, 0, &fractol_exit, NULL);
	return (false);
}
