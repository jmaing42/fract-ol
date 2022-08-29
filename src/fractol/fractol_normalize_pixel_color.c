/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_normalize_pixel_color.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:41:14 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/29 23:55:21 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned char	fractol_normalize_pixel_color(long double f)
{
	f *= 255;
	if (f <= 0)
		return (0);
	if (f >= 255)
		return (255);
	return ((unsigned char)f);
}
