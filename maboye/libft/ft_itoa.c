/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:57:04 by maboye            #+#    #+#             */
/*   Updated: 2019/01/08 20:04:15 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_intlen(long nb)
{
	int		i;

	i = 0;
	while (nb /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		x;
	long	nb;

	nb = (long)n;
	x = ft_intlen(nb);
	if (!(str = ft_strnew(x + (nb < 0 ? 2 : 1))))
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
		x++;
	}
	str[x + 1] = '\0';
	while (nb >= 10)
	{
		str[x] = nb % 10 + '0';
		nb = nb / 10;
		x--;
	}
	str[x] = nb + '0';
	return (str);
}
