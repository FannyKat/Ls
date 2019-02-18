/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 22:51:29 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:25:03 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_capitalize(char *s)
{
	char	*new;
	int		i;

	if (!s || !(new = ft_strnew(ft_strlen(s))))
		return (NULL);
	new[0] = ft_toupper(s[0]);
	i = 0;
	while (s[++i])
		if (!ft_isalnum(s[i - 1]) && ft_isalnum(s[i]))
			new[i] = ft_toupper(s[i]);
		else
			new[i] = s[i];
	return (new);
}
