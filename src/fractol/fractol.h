/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:29:15 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/28 17:41:02 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stddef.h>
# include <stdint.h>

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

t_err		fractol_init_options(t_fractol_options *out);
t_err		fractol_init(t_fractol *out, t_fractol_options *option);

t_err		fractol_render(t_fractol *param);
uint32_t	fractol_get_pixel(t_fractol *param, size_t x, size_t y);

uint8_t		fractol_pixel_color(long double f);

typedef union u_fractol_pixel
{
	struct s_fractol_pixel_color {
		uint8_t	a;
		uint8_t	r;
		uint8_t	g;
		uint8_t	b;
	}			color;
	uint32_t	pixel;
}	t_fractol_pixel;

#endif
