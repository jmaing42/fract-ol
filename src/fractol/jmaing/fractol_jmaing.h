/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_jmaing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:20:32 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/03 16:21:27 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_JMAING_H
# define FRACTOL_JMAING_H

# include "fractol.h"

t_err	fractol_jmaing_init(
			t_fractol_options_get_pixel *out_get_pixel,
			t_fto_disposable **out_extra,
			size_t argc,
			char **argv);

#endif
