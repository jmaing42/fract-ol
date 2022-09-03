/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:10:47 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/03 15:12:57 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "ft_types_cstring.h"

static void	assert(bool must_be_true)
{
	if (!must_be_true)
		exit(EXIT_FAILURE);
}

int	main(void)
{
	assert(ft_types_cstring_equals("", ""));
	assert(ft_types_cstring_equals("Hello", "Hello"));
	assert(!ft_types_cstring_equals("Hello", "Hello!"));
	assert(!ft_types_cstring_equals("Hello!", "Hello"));
	assert(!ft_types_cstring_equals("HelLo", "Hello"));
	assert(!ft_types_cstring_equals("Hello", "hello"));
	assert(!ft_types_cstring_equals("hello", ""));
	assert(!ft_types_cstring_equals("", "hello"));
	return (EXIT_SUCCESS);
}
