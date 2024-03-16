/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:25:00 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/03/17 00:38:48 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#include <mlx.h>

#include<stdio.h>

static void	*routine(void *param)
{
	t_fractol_thread *const	self = param;
	size_t					i;

	sem_wait(self->self->semaphore);
	i = (size_t)-1;
	while (++i < self->self->options->window_w)
		fractol_render_pixel(self->self, &self->self->img, i, self->y);
	sem_post(self->self->semaphore);
	return (NULL);
}

static t_err	start_line(t_fractol *param, size_t y)
{
	if (pthread_create(&param->threads[y].thread,
			NULL, routine, &param->threads[y]))
		return (true);
	return (false);
}

t_err	fractol_render(t_fractol *param)
{
	size_t	i;

	i = (size_t)-1;
	while (++i < param->options->window_h)
		if (start_line(param, i))
			return (true);
	i = (size_t)-1;
	while (++i < param->options->window_h)
		pthread_join(param->threads[i].thread, NULL);
	mlx_put_image_to_window(
		param->mlx_context, param->mlx_window, param->image, 0, 0);
	return (false);
}
