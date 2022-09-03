/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_jmaing_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:20:12 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/03 16:31:57 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_jmaing.h"

#include <stdlib.h>
#include <unistd.h>

#include "ft_types_cstring.h"
#include "ft_io.h"
#include "ft_exit.h"

#include "fractol_jmaing_mieum.h"
#include "fractol_jmaing_siot.h"

t_err	fractol_jmaing_init(
	t_fractol_options_get_pixel *out_get_pixel,
	t_fto_disposable **out_extra,
	size_t argc,
	char **argv
)
{
	argc--;
	argv++;
	if (argc && ft_types_cstring_equals(argv[0], "mieum"))
		return (
			fractol_jmaing_mieum_init(out_get_pixel, out_extra, argc, argv)
		);
	if (argc && ft_types_cstring_equals(argv[0], "siot"))
		return (
			fractol_jmaing_siot_init(out_get_pixel, out_extra, argc, argv)
		);
	if (ft_io_write(
			STDOUT_FILENO,
			"available subcommands of jmaing: mieum, siot\n",
			45))
		ft_exit(EXIT_FAILURE);
	ft_exit(EXIT_SUCCESS);
	return (false);
}
