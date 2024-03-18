/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:29:18 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/03/18 22:51:17 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdlib.h>
#include <limits.h>
#include <mlx.h>

#include "ft_assert.h"

#include "fractol_hooks.h"
#include "ft_cpu_count.h"

static t_err	init_threads(t_fractol_options *options, t_fractol *out)
{
	size_t	i;
	int		cpu_count;

	if (ft_cpu_count(&cpu_count))
		return (true);
	sem_unlink("");
	out->semaphore = sem_open("", O_CREAT | O_EXCL, 0644, cpu_count);
	if (out->semaphore == SEM_FAILED)
		return (true);
	out->threads = malloc(sizeof(t_fractol_thread) * options->window_h);
	if (!out->threads)
	{
		sem_close(out->semaphore);
		return (true);
	}
	i = (size_t)-1;
	while (++i < options->window_h)
	{
		out->threads[i].self = out;
		out->threads[i].y = i;
	}
	return (false);
}

t_err	fractol_init(t_fractol *out, t_fractol_options *options)
{
	out->options = options;
	out->mlx_context = mlx_init();
	if (!out->mlx_context || options->window_h > INT_MAX
		|| options->window_w > INT_MAX || init_threads(options, out))
		return (true);
	out->mlx_window = ft_assert_nonnull(mlx_new_window(out->mlx_context,
				options->window_w, options->window_h, options->title));
	out->image = ft_assert_nonnull(mlx_new_image(out->mlx_context,
				options->window_w, options->window_h));
	out->img.data = (unsigned char *)mlx_get_data_addr(out->image,
			&out->img.bits_per_pixel, &out->img.size_of_line, &out->img.endian);
	mlx_expose_hook(out->mlx_window, &fractol_hooks_init, out);
	mlx_hook(out->mlx_window, MLX_EVENT_ON_DESTROY, 0, &fractol_hooks_exit, 0);
	mlx_hook(out->mlx_window, MLX_EVENT_ON_KEYDOWN, 0, &fractol_hooks_key, out);
	mlx_hook(out->mlx_window, MLX_EVENT_ON_MOUSE, 0, &fractol_hooks_mouse, out);
	out->center = fractol_position(0.0L, 0.0L);
	out->size = 4.2L / options->window_w;
	return (false);
}
