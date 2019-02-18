/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:37:46 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:30:03 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		x;
	int		i;
	int		len;
	int		start;
	char	**str;

	if (!s || !c || !(str = (char**)malloc((
	ft_wordcount((char*)s, c) + 1) * sizeof(char*))))
		return (NULL);
	x = 0;
	i = -1;
	while (++i < ft_wordcount((char*)s, c))
	{
		len = 0;
		while (s[x] == c && s[x])
			x++;
		start = x;
		while (s[x] != c && s[x++])
			len++;
		if (!(str[i] = ft_strsub(s, start, len)))
			return (NULL);
	}
	str[i] = NULL;
	return (str);
}
