/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:53:54 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:27:17 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstsort(t_list **begin_list, int (*cmp)())
{
	t_list	*temp;
	t_list	*temp2;
	void	*stock;

	if (!begin_list)
		return ;
	temp2 = *begin_list;
	while (temp2->next)
	{
		temp = temp2->next;
		while (temp)
		{
			if (cmp(temp2->content, temp2->next->content) > 0)
			{
				stock = temp2->content;
				temp2->content = temp->content;
				temp->content = stock;
			}
			temp = temp->next;
		}
		temp2 = temp2->next;
	}
}
