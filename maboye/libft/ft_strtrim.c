/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:19:27 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:30:12 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*tmp;
	size_t	x;
	size_t	len_tmp;

	x = 0;
	if (!s)
		return (NULL);
	len_tmp = ft_strlen(s);
	while (ft_isspace((int)s[x]))
		x++;
	while (ft_isspace((int)s[len_tmp - 1]))
		len_tmp--;
	if (x == ft_strlen(s))
	{
		if (!(tmp = ft_strsub(s, 0, 0)))
			return (NULL);
		return (tmp);
	}
	if (!(tmp = ft_strsub(s, x, (len_tmp - x))))
		return (NULL);
	return (tmp);
}
