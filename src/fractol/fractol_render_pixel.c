/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render_pixel.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:41:16 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/29 23:52:46 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <limits.h>

static void	fractol_render_pixel_32le(
	t_fractol *param,
	unsigned char *address_of_pixel_data,
	size_t x,
	size_t y
)
{
	const t_fractol_pixel	color = fractol_get_pixel(param, x, y);

	address_of_pixel_data[0] = fractol_normalize_pixel_color(color.b);
	address_of_pixel_data[1] = fractol_normalize_pixel_color(color.g);
	address_of_pixel_data[2] = fractol_normalize_pixel_color(color.r);
	address_of_pixel_data[3] = 0;
}

static void	fractol_render_pixel_32be(
	t_fractol *param,
	unsigned char *address_of_pixel_data,
	size_t x,
	size_t y
)
{
	const t_fractol_pixel	color = fractol_get_pixel(param, x, y);

	address_of_pixel_data[1] = 0;
	address_of_pixel_data[2] = fractol_normalize_pixel_color(color.r);
	address_of_pixel_data[3] = fractol_normalize_pixel_color(color.g);
	address_of_pixel_data[4] = fractol_normalize_pixel_color(color.b);
}

static void	fractol_render_pixel_24le(
	t_fractol *param,
	unsigned char *address_of_pixel_data,
	size_t x,
	size_t y
)
{
	const t_fractol_pixel	color = fractol_get_pixel(param, x, y);

	address_of_pixel_data[0] = fractol_normalize_pixel_color(color.b);
	address_of_pixel_data[1] = fractol_normalize_pixel_color(color.g);
	address_of_pixel_data[2] = fractol_normalize_pixel_color(color.r);
}

static void	fractol_render_pixel_24be(
	t_fractol *param,
	unsigned char *address_of_pixel_data,
	size_t x,
	size_t y
)
{
	const t_fractol_pixel	color = fractol_get_pixel(param, x, y);

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
	const size_t	index
		= image->size_of_line * y + image->bits_per_pixel / 8 * x;

	if (image->bits_per_pixel == 32 && image->endian == 0 && CHAR_BIT == 8)
		fractol_render_pixel_32le(param, &image->data[index], x, y);
	else if (image->bits_per_pixel == 32 && image->endian == 1 && CHAR_BIT == 8)
		fractol_render_pixel_32be(param, &image->data[index], x, y);
	else if (image->bits_per_pixel == 24 && image->endian == 0 && CHAR_BIT == 8)
		fractol_render_pixel_24le(param, &image->data[index], x, y);
	else if (image->bits_per_pixel == 24 && image->endian == 1 && CHAR_BIT == 8)
		fractol_render_pixel_24be(param, &image->data[index], x, y);
	else
		return (true);
	return (false);
}
