/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:01:12 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/03/11 22:17:28 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math_complex.h"

#include <stddef.h>

size_t	fractol_julia(t_ft_math_complex z, t_ft_math_complex c, size_t limit)
{
	size_t	n;

	n = -1;
	while (++n < limit && ft_math_complex_abs_square(z) <= 4.0L)
		z = ft_math_complex_add(ft_math_complex_multiply(z, z), c);
	return (n);
}
