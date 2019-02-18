/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 02:51:26 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:26:36 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstfind(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*temp;

	if (!begin_list)
		return (NULL);
	temp = begin_list;
	while (temp)
	{
		if (cmp(temp->content, data_ref) == 0)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
