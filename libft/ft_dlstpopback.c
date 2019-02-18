/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpopback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:31:03 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:24:54 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_dlstpopback(t_dlist *li)
{
	t_dlistn	*tmp;

	if (ft_dlstisempty(li))
		return (NULL);
	if (li->begin == li->end)
	{
		free(li);
		li = NULL;
		return (NULL);
	}
	tmp = li->end;
	li->end = li->end->back;
	li->end->next = NULL;
	tmp->next = NULL;
	tmp->back = NULL;
	free(tmp);
	tmp = NULL;
	li->length--;
	return (li);
}
