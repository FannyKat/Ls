/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:37:50 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:30:09 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	x;

	if (!s || !(tmp = ft_strnew(len)))
		return (NULL);
	x = -1;
	while (++x < len)
		tmp[x] = s[start++];
	return (tmp);
}
