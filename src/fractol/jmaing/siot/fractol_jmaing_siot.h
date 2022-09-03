/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_jmaing_siot.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 00:55:59 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/02 01:06:10 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_JMAING_SIOT_H
# define FRACTOL_JMAING_SIOT_H

# include <stddef.h>

# include "fractol.h"

size_t	fractol_jmaing_siot(t_fractol_position c, size_t limit);

t_err	fractol_jmaing_siot_init(
			t_fractol_options_get_pixel *out_get_pixel,
			t_fto_disposable **out_extra,
			size_t argc,
			char **argv);

#endif
