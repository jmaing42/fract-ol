#include "fractol.h"

#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <mlx.h>

#include "ft_assert.h"

int	main(void)
{
	t_fractol			fractol;
	t_fractol_options	options;

	if (fractol_init_options(&options) || fractol_init(&fractol, &options))
		return (EXIT_FAILURE);
	mlx_loop(fractol.mlx_context);
	return (EXIT_SUCCESS);
}

t_err	fractol_render(t_fractol *param)
{
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	uint32_t *const	data = (uint32_t *)ft_assert_nonnull(mlx_get_data_addr(
				param->back, &bits_per_pixel, &size_line, &endian));
	size_t			i;

	// /*
	i = -1;
	while (++i < param->options->window_w * param->options->window_h)
	{
		data[
			size_line / (bits_per_pixel / CHAR_BIT)
			* (i / param->options->window_w)
			+ (i % param->options->window_w)
		] = 0x00FFFF00;
	}
	/*/
	i = -1;
	while (++i < 320)
	{
		data[
			size_line / (bits_per_pixel / CHAR_BIT)
			* i
			+ 2 * i
		] = 0x00FFFF00;
	}
	//*/
	mlx_put_image_to_window(
		param->mlx_context, param->mlx_window, param->back, 0, 0);
	return (false);
}
