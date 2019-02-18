/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpushfront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:26:14 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:35:56 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_dlstpushfront(t_dlist *li, int x)
{
	t_dlistn	*element;

	if (!(element = malloc(sizeof(*element))))
		return (NULL);
	element->content_size = x;
	element->next = NULL;
	element->back = NULL;
	if (ft_dlstisempty(li))
	{
		if (!(li = malloc(sizeof(*li))))
			return (NULL);
		li->length = 0;
		li->begin = element;
		li->end = element;
	}
	else
	{
		li->begin->back = element;
		element->next = li->end;
		li->begin = element;
	}
	li->length++;
	return (li);
}
