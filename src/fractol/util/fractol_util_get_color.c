/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_util_get_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 01:58:08 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/03 00:47:58 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_util.h"

#include "ft_math_complex.h"

#define STEPS 3

static const t_fractol_pixel	g_black = {0.0L, 0.0L, 0.0L};

static const t_fractol_pixel	g_colors[6] = {
{1.0L, 0.0L, 0.0L},
{1.0L, 1.0L, 0.0L},
{0.0L, 1.0L, 0.0L},
{0.0L, 1.0L, 1.0L},
{0.0L, 0.0L, 1.0L},
{1.0L, 0.0L, 1.0L},
};

t_fractol_pixel	fractol_util_get_color(size_t size, size_t limit)
{
	t_fractol_pixel		current;
	t_fractol_pixel		next;
	t_fractol_pixel		result;
	const long double	alpha
		= 1.0L - (1.0L - 1.0L / limit * size) * (1.0L - 1.0L / limit * size);

	if (size == limit)
		return (g_black);
	current = g_colors[size / STEPS % 6];
	current.r = 1.0L - ((1.0L - current.r) * alpha);
	current.g = 1.0L - ((1.0L - current.g) * alpha);
	current.b = 1.0L - ((1.0L - current.b) * alpha);
	next = g_colors[(size / STEPS + 1) % 6];
	next.r = 1.0L - ((1.0L - next.r) * alpha);
	next.g = 1.0L - ((1.0L - next.g) * alpha);
	next.b = 1.0L - ((1.0L - next.b) * alpha);
	result.r = (current.r * (STEPS - size % STEPS)
			+ next.r * (size % STEPS)) / STEPS;
	result.g = (current.g * (STEPS - size % STEPS)
			+ next.g * (size % STEPS)) / STEPS;
	result.b = (current.b * (STEPS - size % STEPS)
			+ next.b * (size % STEPS)) / STEPS;
	return (result);
}
