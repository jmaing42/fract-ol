/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_complex.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 00:22:59 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/03/11 22:17:02 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_COMPLEX_H
# define FT_MATH_COMPLEX_H

typedef struct s_ft_math_complex
{
	long double	real;
	long double	imaginary;
}	t_ft_math_complex;

t_ft_math_complex	ft_math_complex(
						long double real,
						long double imaginary);

long double			ft_math_complex_abs_square(
						t_ft_math_complex c);

t_ft_math_complex	ft_math_complex_add(
						t_ft_math_complex lhs,
						t_ft_math_complex rhs);

t_ft_math_complex	ft_math_complex_multiply(
						t_ft_math_complex lhs,
						t_ft_math_complex rhs);

#endif
