/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:31:24 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/28 17:32:24 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_assert.h"

#include "ft_types.h"
#include "ft_exit.h"

void	ft_assert(bool must_be_true)
{
	if (!must_be_true)
		ft_exit(EXIT_FAILURE);
}
