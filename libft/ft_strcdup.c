/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 00:42:00 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:40:19 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcdup(char *src, char c)
{
	char	*dst;
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i] != '\0' && src[i] != c)
		i++;
	if (!(dst = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (src[i] != '\0' && src[i] != c)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
