/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:29:18 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/01 09:24:49 by Juyeong Maing    ###   ########.fr       */
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
#define MLX_EVENT_ON_MOUSE 4
#define MLX_EVENT_ON_MOUSE_MOVE 6
#define MLX_EVENT_ON_DESTROY 17

#define MLX_BUTTON_LEFT 1
#define MLX_BUTTON_RIGHT 2
#define MLX_BUTTON_MIDDLE 3
#define MLX_BUTTON_SCROLL_UP 4
#define MLX_BUTTON_SCROLL_DOWN 5

#define MLX_KEY_A 0
#define MLX_KEY_S 1
#define MLX_KEY_D 2
#define MLX_KEY_Q 12
#define MLX_KEY_W 13
#define MLX_KEY_E 14
#define MLX_KEY_R 15
#define MLX_KEY_ESC 53

static int	key_press(int keycode, t_fractol *param)
{
	(void)param;
	if (keycode == MLX_KEY_ESC)
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

#include <stdio.h>

int	mouse(int button, int x, int y, t_fractol *param)
{
	(void)x;
	(void)y;
	if (button == MLX_BUTTON_SCROLL_UP)
	{
		param->size *= 1.1;
		fractol_render(param);
	}
	else if (button == MLX_BUTTON_SCROLL_DOWN)
	{
		param->size /= 1.1;
		fractol_render(param);
	}
	else if (button == MLX_BUTTON_LEFT)
	{
		param->center.x
			+= (x - (int)param->options->window_w / 2) * param->size;
		param->center.y
			+= (y - (int)param->options->window_h / 2) * param->size;
		printf("%Lf, %Lf\n", param->center.x, param->center.y);
		printf("%d, %d\n", x, y);
		fractol_render(param);
	}
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
	mlx_hook(out->mlx_window, MLX_EVENT_ON_MOUSE, 0, mouse, out);
	out->center = fractol_position(0.0L, 0.0L);
	out->size = 4.2L / options->window_w;
	return (false);
}
