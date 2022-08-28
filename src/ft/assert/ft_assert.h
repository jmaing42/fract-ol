/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:16:07 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/28 17:32:30 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ASSERT_H
# define FT_ASSERT_H

# include <stdbool.h>

void	ft_assert(bool must_be_true);
void	*ft_assert_nonnull(void *value);

#endif
