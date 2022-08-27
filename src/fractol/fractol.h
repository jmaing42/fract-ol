#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_types.h"

typedef struct s_fractol
{
	void	*mlx_context;
	void	*mlx_window;
	void	*front;
	void	*back;
}	t_fractol;

typedef struct s_fractol_options
{
	int		window_w;
	int		window_h;
	char	*title;
}	t_fractol_options;

t_err	fractol_init_options(t_fractol_options *out);
t_err	fractol_init(t_fractol *out, t_fractol_options *option);

#endif
