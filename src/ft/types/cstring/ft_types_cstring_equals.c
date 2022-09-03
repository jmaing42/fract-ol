/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_cstring_equals.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:43:16 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/03 15:11:35 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types_cstring.h"

bool	ft_types_cstring_equals(const char *lhs, const char *rhs)
{
	while (*lhs && *rhs && *lhs++ == *rhs++)
		;
	return (!*lhs && !*rhs);
}
