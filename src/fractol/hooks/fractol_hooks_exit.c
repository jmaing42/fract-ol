/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hooks_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:46:43 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/01 22:50:22 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_hooks.h"

#include <stdlib.h>

#include "ft_exit.h"

int	fractol_hooks_exit(int unused, void *param)
{
	(void)unused;
	(void)param;
	ft_exit(EXIT_SUCCESS);
	return (0);
}
