/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_todec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 09:13:11 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:25:33 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_hex_todec(char *hex)
{
	int		dec;
	int		temp;

	dec = 0;
	temp = 0;
	while (*hex != '\0')
	{
		if (ft_islowhexa(*hex))
			temp = *hex - 'a' + 10;
		else if (ft_isupphexa(*hex))
			temp = *hex - 'A' + 10;
		else if (ft_isdigit(*hex))
			temp = *hex - '0';
		dec = dec * 16 + temp;
		hex++;
	}
	return (dec);
}
