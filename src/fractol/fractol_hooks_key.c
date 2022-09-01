/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hooks_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:47:32 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/01 22:49:05 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_hooks.h"

#include <stdlib.h>

#include "ft_exit.h"

int	fractol_hooks_key(int keycode, t_fractol *param)
{
	(void)param;
	if (keycode == MLX_KEY_ESC)
		ft_exit(EXIT_SUCCESS);
	fractol_render(param);
	return (0);
}
