/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 03:08:40 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:26:51 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpushfront(t_list **begin_list, void *data)
{
	t_list	*tmp;

	tmp = ft_lstaddelem(data);
	tmp->next = *begin_list;
	*begin_list = tmp;
}
