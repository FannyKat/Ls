/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 09:08:35 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:06:31 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strnlen(const char *s, size_t len_max)
{
	const char	*ptr;

	if (!s)
		return (0);
	ptr = s;
	while (len_max-- > 0 && *ptr)
		ptr++;
	return (ptr - s);
}
