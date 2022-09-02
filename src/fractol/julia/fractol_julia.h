/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:01:17 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/03 00:51:17 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_JULIA_H
# define FRACTOL_JULIA_H

# include "fractol.h"

# include <stddef.h>

# include "ft_math_complex.h"

size_t	fractol_julia(t_ft_math_complex z, t_ft_math_complex c, size_t limit);

typedef struct s_fractol_julia
{
	t_fto_disposable	super;
	t_ft_math_complex	z;
}	t_fractol_julia;

t_err	fractol_julia_init(
			t_fractol_options_get_pixel *out_get_pixel,
			t_fto_disposable **out_extra,
			size_t argc,
			char **argv);

#endif
