/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:25:00 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/29 23:44:01 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <mlx.h>

t_err	fractol_render(t_fractol *param)
{
	t_mlx_image		image;
	size_t			x;
	size_t			y;

	image.data
		= (unsigned char *)mlx_get_data_addr(
			param->image,
			&image.bits_per_pixel,
			&image.size_of_line,
			&image.endian);
	if (!image.data)
		return (true);
	y = -1;
	while (++y < param->options->window_h)
	{
		x = -1;
		while (++x < param->options->window_w)
		{
			fractol_render_pixel(param, &image, x, y);
		}
	}
	mlx_put_image_to_window(
		param->mlx_context, param->mlx_window, param->image, 0, 0);
	return (false);
}
