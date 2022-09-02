/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render_pixel.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:41:16 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/03 01:00:52 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <limits.h>

static void	fractol_render_pixel_32le(
	t_fractol_options *options,
	unsigned char *address_of_pixel_data,
	t_fractol_position position
)
{
	const t_fractol_pixel	color = options->get_pixel(options, position);

	address_of_pixel_data[0] = fractol_normalize_pixel_color(color.b);
	address_of_pixel_data[1] = fractol_normalize_pixel_color(color.g);
	address_of_pixel_data[2] = fractol_normalize_pixel_color(color.r);
	address_of_pixel_data[3] = 0;
}

static void	fractol_render_pixel_32be(
	t_fractol_options *options,
	unsigned char *address_of_pixel_data,
	t_fractol_position position
)
{
	const t_fractol_pixel	color = options->get_pixel(options, position);

	address_of_pixel_data[1] = 0;
	address_of_pixel_data[2] = fractol_normalize_pixel_color(color.r);
	address_of_pixel_data[3] = fractol_normalize_pixel_color(color.g);
	address_of_pixel_data[4] = fractol_normalize_pixel_color(color.b);
}

static void	fractol_render_pixel_24le(
	t_fractol_options *options,
	unsigned char *address_of_pixel_data,
	t_fractol_position position
)
{
	const t_fractol_pixel	color = options->get_pixel(options, position);

	address_of_pixel_data[0] = fractol_normalize_pixel_color(color.b);
	address_of_pixel_data[1] = fractol_normalize_pixel_color(color.g);
	address_of_pixel_data[2] = fractol_normalize_pixel_color(color.r);
}

static void	fractol_render_pixel_24be(
	t_fractol_options *options,
	unsigned char *address_of_pixel_data,
	t_fractol_position position
)
{
	const t_fractol_pixel	color = options->get_pixel(options, position);

	address_of_pixel_data[0] = fractol_normalize_pixel_color(color.r);
	address_of_pixel_data[1] = fractol_normalize_pixel_color(color.g);
	address_of_pixel_data[2] = fractol_normalize_pixel_color(color.b);
}

t_err	fractol_render_pixel(
	t_fractol *param,
	t_mlx_image *image,
	size_t x,
	size_t y
)
{
	t_fractol_options *const	options = param->options;
	const long double			x_from_center = options->window_w * -0.5L + x;
	const long double			y_from_center = options->window_h * -0.5L + y;
	const t_fractol_position	position
		= fractol_position(
			param->center.x + x_from_center * param->size,
			param->center.y + y_from_center * param->size);
	const size_t				index
		= image->size_of_line * y + image->bits_per_pixel / 8 * x;

	if (image->bits_per_pixel == 32 && image->endian == 0 && CHAR_BIT == 8)
		fractol_render_pixel_32le(options, &image->data[index], position);
	else if (image->bits_per_pixel == 32 && image->endian == 1 && CHAR_BIT == 8)
		fractol_render_pixel_32be(options, &image->data[index], position);
	else if (image->bits_per_pixel == 24 && image->endian == 0 && CHAR_BIT == 8)
		fractol_render_pixel_24le(options, &image->data[index], position);
	else if (image->bits_per_pixel == 24 && image->endian == 1 && CHAR_BIT == 8)
		fractol_render_pixel_24be(options, &image->data[index], position);
	else
		return (true);
	return (false);
}
