/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 02:23:30 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:26:48 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpushback(t_list **begin_list, void *data)
{
	t_list	*temp;

	temp = *begin_list;
	if (!temp)
	{
		*begin_list = ft_lstaddelem(data);
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = ft_lstaddelem(data);
}
