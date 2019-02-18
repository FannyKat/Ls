/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 09:07:27 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:29:46 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s, size_t n)
{
	char	*tmp;

	if (!s || !(tmp = ft_strnew(n)))
		return (NULL);
	tmp = ft_strncpy(tmp, s, n);
	return (tmp);
}
