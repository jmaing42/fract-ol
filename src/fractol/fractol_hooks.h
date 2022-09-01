/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hooks.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:44:45 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/01 23:51:48 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_HOOKS_H
# define FRACTOL_HOOKS_H

# include "fractol.h"

# define MLX_EVENT_ON_KEYDOWN 2
# define MLX_EVENT_ON_KEYUP 3
# define MLX_EVENT_ON_MOUSE 4
# define MLX_EVENT_ON_MOUSE_MOVE 6
# define MLX_EVENT_ON_DESTROY 17

# define MLX_KEY_A 0
# define MLX_KEY_S 1
# define MLX_KEY_D 2
# define MLX_KEY_Q 12
# define MLX_KEY_W 13
# define MLX_KEY_E 14
# define MLX_KEY_R 15
# define MLX_KEY_ESC 53

# define MLX_BUTTON_LEFT 1
# define MLX_BUTTON_RIGHT 2
# define MLX_BUTTON_MIDDLE 3
# define MLX_BUTTON_SCROLL_UP 4
# define MLX_BUTTON_SCROLL_DOWN 5

int	fractol_hooks_init(void *param);
int	fractol_hooks_exit(int unused, void *param);
int	fractol_hooks_key(int keycode, t_fractol *param);
int	fractol_hooks_mouse(int button, int x, int y, t_fractol *param);

#endif
