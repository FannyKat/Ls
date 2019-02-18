/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:46:21 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:28:55 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *str, int c)
{
	int		x;
	char	*tmp;
	int		len_str;

	x = -1;
	tmp = (char*)str;
	len_str = ft_strlen(tmp);
	while (++x < (len_str + 1))
		if (tmp[x] == (char)c)
			return (&tmp[x]);
	return (NULL);
}
