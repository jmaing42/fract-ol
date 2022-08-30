/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 00:21:44 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/31 02:15:06 by Juyeong Maing    ###   ########.fr       */
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
	while (++n < limit && ft_math_complex_abs(z) <= 2L)
		z = ft_math_complex_add(ft_math_complex_multiply(z, z), c);
	return (n);
}
