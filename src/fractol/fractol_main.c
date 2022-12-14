/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:29:20 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/03 01:06:36 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdlib.h>
#include <mlx.h>

int	main(int argc, char **argv)
{
	t_fractol			fractol;
	t_fractol_options	options;

	if (
		fractol_init_options(&options, argc, argv)
		|| fractol_init(&fractol, &options)
	)
		return (EXIT_FAILURE);
	mlx_loop(fractol.mlx_context);
	return (EXIT_SUCCESS);
}
