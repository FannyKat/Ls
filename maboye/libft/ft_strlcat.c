/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:46:31 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:29:32 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	if (size < dest_len)
		return (size + ft_strlen((char*)src));
	while (src[i] && dest_len < size - 1)
		dest[dest_len++] = src[i++];
	dest[dest_len] = '\0';
	return (ft_strlen((char*)src) + dest_len - i);
}
