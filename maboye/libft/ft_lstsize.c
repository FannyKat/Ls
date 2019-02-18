/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 03:28:53 by maboye            #+#    #+#             */
/*   Updated: 2019/02/11 04:14:22 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstsize(t_list *source)
{
	int		count;
	t_list	*begin;

	count = 1;
	if (!source)
		return (0);
	begin = source;
	while (source->next)
	{
		count++;
		source = source->next;
	}
	source = begin;
	return (count);
}
