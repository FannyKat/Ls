/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:46:02 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:27:32 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_tmp;
	unsigned char	*s2_tmp;
	size_t			x;

	if (!s1 || !s2)
		return (0);
	s1_tmp = (unsigned char*)s1;
	s2_tmp = (unsigned char*)s2;
	x = -1;
	while (++x < n && s1_tmp[x] == s2_tmp[x])
		;
	if (x == n)
		return (0);
	return (s1_tmp[x] - s2_tmp[x]);
}
