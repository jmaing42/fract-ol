#ifndef FRACTOL_H
# define FRACTOL_H

# include <stddef.h>

# include "ft_types.h"

typedef struct s_fractol_options
{
	size_t	window_w;
	size_t	window_h;
	char	*title;
}	t_fractol_options;

typedef struct s_fractol
{
	void				*mlx_context;
	void				*mlx_window;
	void				*front;
	void				*back;
	t_fractol_options	*options;
}	t_fractol;

t_err	fractol_init_options(t_fractol_options *out);
t_err	fractol_init(t_fractol *out, t_fractol_options *option);

t_err	fractol_render(t_fractol *param);

#endif
