/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:01:28 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:28:16 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	base_true(const char *base)
{
	int	x;
	int	y;

	x = -1;
	if (base[0] == '\0')
		return (0);
	while (base[++x])
	{
		y = -1;
		while (base[++y])
			if ((x != y && base[x] == base[y]) ||
			base[y] == '+' || base[y] == '-')
				return (0);
	}
	return (1);
}

void		ft_putnbr_base(int nbr, const char *base)
{
	unsigned int x;

	if (base_true(base))
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			x = nbr * -1;
		}
		else
			x = nbr;
		if (x >= ft_strlen(base))
			ft_putnbr_base(x / ft_strlen(base), base);
		ft_putchar(base[x % ft_strlen(base)]);
	}
}
