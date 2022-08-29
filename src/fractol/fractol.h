/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:29:15 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/30 00:39:20 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stddef.h>

# include "ft_types.h"

typedef struct s_fractol_options
{
	size_t	window_w;
	size_t	window_h;
	char	*title;
}	t_fractol_options;

typedef struct s_fractol
{
	void				*mlx_context;
	void				*mlx_window;
	void				*image;
	t_fractol_options	*options;
}	t_fractol;

typedef struct s_fractol_pixel
{
	long double	r;
	long double	g;
	long double	b;
}	t_fractol_pixel;

typedef struct s_fractol_position
{
	long double	x;
	long double	y;
}	t_fractol_position;

typedef struct s_mlx_image
{
	int				bits_per_pixel;
	int				size_of_line;
	int				endian;
	unsigned char	*data;
}	t_mlx_image;

t_err				fractol_init_options(
						t_fractol_options *out);
t_err				fractol_init(
						t_fractol *out, t_fractol_options *option);
t_err				fractol_render(
						t_fractol *param);
t_err				fractol_render_pixel(
						t_fractol *param,
						t_mlx_image *image,
						size_t x,
						size_t y);
t_fractol_position	fractol_get_pixel_position(
						t_fractol *param,
						size_t x,
						size_t y);
t_fractol_pixel		fractol_get_color(
						t_fractol_position position);
unsigned char		fractol_normalize_pixel_color(
						long double f);
t_fractol_pixel		fractol_get_pixel(
						t_fractol *param,
						size_t x,
						size_t y);

#endif
