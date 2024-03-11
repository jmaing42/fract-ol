/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 00:21:44 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/03/11 22:17:37 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math_complex.h"

#include <stddef.h>

size_t	fractol_mandelbrot(t_ft_math_complex c, size_t limit)
{
	t_ft_math_complex	z;
	size_t				n;

	z = ft_math_complex(0, 0);
	n = -1;
	while (++n < limit && ft_math_complex_abs_square(z) <= 4.0L)
		z = ft_math_complex_add(ft_math_complex_multiply(z, z), c);
	return (n);
}
