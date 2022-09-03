/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init_options.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 01:02:16 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/03 16:31:51 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <unistd.h>

#include "ft_types_cstring.h"
#include "ft_io.h"
#include "ft_exit.h"

#include "fractol_mandelbrot.h"
#include "fractol_julia.h"
#include "fractol_jmaing.h"

static t_err	init_rest(t_fractol_options *out, size_t ac, char **av)
{
	if (ac && ft_types_cstring_equals(av[0], "mandelbrot"))
		return (fractol_mandelbrot_init(&out->get_pixel, &out->extra, ac, av));
	if (ac && ft_types_cstring_equals(av[0], "julia"))
		return (fractol_julia_init(&out->get_pixel, &out->extra, ac, av));
	if (ac && ft_types_cstring_equals(av[0], "jmaing"))
		return (fractol_jmaing_init(&out->get_pixel, &out->extra, ac, av));
	if (ft_io_write(
			STDOUT_FILENO,
			"available subcommands: mandelbrot, julia, jmaing\n",
			49))
		ft_exit(EXIT_FAILURE);
	ft_exit(EXIT_SUCCESS);
}

t_err	fractol_init_options(t_fractol_options *out, size_t argc, char **argv)
{
	out->title = argv[0];
	out->window_w = 640;
	out->window_h = 480;
	return (init_rest(out, argc - 1, argv + 1));
}
