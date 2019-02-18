/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:46:08 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:27:41 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*tmp;

	if (!src || !dest)
		return (NULL);
	if (!(tmp = ft_strnew(len + 1)))
		return (dest);
	ft_memcpy(tmp, src, len);
	ft_memcpy(dest, tmp, len);
	free(tmp);
	return (dest);
}
