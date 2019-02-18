/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 03:15:28 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:26:43 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstmerge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*temp;

	temp = *begin_list1;
	if (!temp)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	if (!begin_list2)
		return ;
	while (temp->next)
		temp = temp->next;
	temp->next = begin_list2;
}
