/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_pixel_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:41:14 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/28 17:43:51 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint8_t	fractol_pixel_color(long double f)
{
	f *= 255;
	if (f < 0)
		f = 0;
	if (f > 255)
		f = 255;
	return ((uint8_t)f);
}
