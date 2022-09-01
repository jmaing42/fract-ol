/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_jmaing_mieum.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 00:55:59 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/02 01:26:28 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_jmaing_mieum.h"

#include <stdio.h>

size_t	fractol_jmaing_mieum(t_fractol_position c, size_t limit)
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
		x *= 4;
		y *= 4;
		if (((int)x == 1 || (int)x == 2) && ((int)y == 1 || (int)y == 2))
			break ;
		x = x - (int)x;
		y = y - (int)y;
	}
	return (n);
}
