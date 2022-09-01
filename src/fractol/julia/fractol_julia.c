#include "ft_math_complex.h"

#include <stddef.h>

size_t	fractol_julia(t_ft_math_complex z, t_ft_math_complex c, size_t limit)
{
	size_t				n;

	n = -1;
	while (++n < limit && ft_math_complex_abs(z) <= 2L)
		z = ft_math_complex_add(ft_math_complex_multiply(z, z), c);
	return (n);
}
