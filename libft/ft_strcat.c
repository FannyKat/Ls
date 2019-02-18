/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:46:18 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:28:48 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *dest, const char *src)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!dest || !src)
		return (NULL);
	while (dest[x])
		x++;
	while (src[y])
		dest[x++] = src[y++];
	dest[x] = '\0';
	return (dest);
}
