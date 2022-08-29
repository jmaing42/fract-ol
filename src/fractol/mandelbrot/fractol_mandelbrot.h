/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 00:21:44 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/30 00:31:36 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_MANDELBROT_H
# define FRACTOL_MANDELBROT_H

# include <stddef.h>

# include "ft_math_complex.h"

size_t	fractol_mandelbrot(t_ft_math_complex c, size_t	limit);

#endif
