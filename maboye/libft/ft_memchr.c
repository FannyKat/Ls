/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:45:57 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:27:30 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	const char	*tmp;
	size_t		x;

	if (!s)
		return (NULL);
	tmp = (const char*)s;
	x = -1;
	while (++x < n)
		if (tmp[x] == (char)c)
			return ((void*)tmp + x);
	return (NULL);
}
