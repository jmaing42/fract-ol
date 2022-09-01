/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_jmaing_siot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 00:55:59 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/02 01:25:12 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_jmaing_siot.h"

#include <stdio.h>

size_t	fractol_jmaing_siot(t_fractol_position c, size_t limit)
{
	long double	x;
	long double	y;
	size_t		n;

	x = c.x;
	y = c.y;
	if (x < 0)
		x = -x;
	if (y < 0)
		y = -y;
	x = x - (int)x;
	y = y - (int)y;
	n = -1;
	while (++n < limit)
	{
		x *= 2;
		y *= 2;
		if ((int)x == 0 && (int)y == 0)
			break ;
		x = x - (int)x;
		y = y - (int)y;
	}
	return (n);
}
