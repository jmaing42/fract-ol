/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:29:20 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/28 19:50:26 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdlib.h>
#include <limits.h>
#include <mlx.h>

#include "ft_assert.h"

int	main(void)
{
	t_fractol			fractol;
	t_fractol_options	options;

	if (fractol_init_options(&options) || fractol_init(&fractol, &options))
		return (EXIT_FAILURE);
	mlx_loop(fractol.mlx_context);
	return (EXIT_SUCCESS);
}

t_err	fractol_render(t_fractol *param)
{
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	uint32_t *const	data = (uint32_t *)ft_assert_nonnull(mlx_get_data_addr(
				param->image, &bits_per_pixel, &size_line, &endian));
	size_t			i;

	ft_assert(bits_per_pixel == 32);
	ft_assert(endian == 0);
	ft_assert(sizeof(t_fractol_pixel) == 4);
	i = -1;
	while (++i < param->options->window_w * param->options->window_h)
	{
		data[
			size_line / 4
			* (i / param->options->window_w)
			+ (i % param->options->window_w)
		] = fractol_get_pixel(
				param,
				i % param->options->window_w,
				i / param->options->window_w,
				endian);
	}
	mlx_put_image_to_window(
		param->mlx_context, param->mlx_window, param->image, 0, 0);
	return (false);
}
