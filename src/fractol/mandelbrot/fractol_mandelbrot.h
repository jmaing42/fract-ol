/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 00:21:44 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/03 00:32:50 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_MANDELBROT_H
# define FRACTOL_MANDELBROT_H

# include "fractol.h"

# include <stddef.h>

# include "ft_math_complex.h"

size_t	fractol_mandelbrot(t_ft_math_complex c, size_t limit);

typedef struct s_fractol_mandelbrot
{
	t_fto_disposable	super;
}	t_fractol_mandelbrot;

t_err	fractol_mandelbrot_init(
			t_fractol_options_get_pixel *out_get_pixel,
			t_fto_disposable *out_extra,
			size_t argc,
			char **argv);

#endif
