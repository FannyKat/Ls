/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 09:10:44 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:29:18 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strfjoin(const char *s1, const char *s2)
{
	char	*tmp;
	size_t	x;
	size_t	y;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(tmp = (char*)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	x = -1;
	y = -1;
	while (++x < len_s1)
		tmp[x] = s1[x];
	while (++y < len_s2)
		tmp[x++] = s2[y];
	tmp[x] = '\0';
	free((void*)s1);
	return (tmp);
}
