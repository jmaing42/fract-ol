/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_complex_abs_square.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 01:29:11 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/03/11 22:16:50 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math_complex.h"

long double	ft_math_complex_abs_square(t_ft_math_complex c)
{
	return (c.real * c.real + c.imaginary * c.imaginary);
}
