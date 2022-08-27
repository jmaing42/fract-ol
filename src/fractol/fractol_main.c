#include <stdlib.h>

#include <mlx.h>

#include "fractol.h"

int	main(void)
{
	t_fractol			fractol;
	t_fractol_options	options;

	if (fractol_init_options(&options) || fractol_init(&fractol, &options))
		return (EXIT_FAILURE);
	mlx_loop(fractol.mlx_context);
	return (EXIT_SUCCESS);
}
