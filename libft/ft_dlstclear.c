/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:07:14 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:24:27 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_dlstclear(t_dlist *li)
{
	if (li)
	{
		while (!ft_dlstisempty(li))
			li = ft_dlstpopback(li);
	}
	return (NULL);
}
