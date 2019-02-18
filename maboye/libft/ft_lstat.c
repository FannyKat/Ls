/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 02:44:29 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:26:28 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstat(t_list *begin_list, unsigned int nbr)
{
	int	i;

	if (begin_list == NULL)
		return (NULL);
	i = nbr;
	while (i-- && begin_list)
		begin_list = begin_list->next;
	return (i >= -1 ? begin_list : NULL);
}
