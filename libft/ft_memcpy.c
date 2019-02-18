/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:46:05 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:27:35 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	x;
	char	*tmp;
	char	*tmp2;

	x = -1;
	if (!dest || !src)
		return (NULL);
	tmp2 = (char*)dest;
	tmp = (char*)src;
	while (++x < n)
		tmp2[x] = tmp[x];
	return (dest);
}
