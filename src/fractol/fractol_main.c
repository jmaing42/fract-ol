/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:29:20 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/29 23:25:45 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdlib.h>
#include <mlx.h>

int	main(void)
{
	t_fractol			fractol;
	t_fractol_options	options;

	if (fractol_init_options(&options) || fractol_init(&fractol, &options))
		return (EXIT_FAILURE);
	mlx_loop(fractol.mlx_context);
	return (EXIT_SUCCESS);
}
