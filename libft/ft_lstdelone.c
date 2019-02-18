/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:21:06 by maboye            #+#    #+#             */
/*   Updated: 2019/02/11 11:14:18 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list **alst)
{
	if (alst)
	{
		ft_memdel(&((*alst)->content));
		ft_memdel(&((*alst)->data));
		ft_memdel((void **)alst);
	}
}
