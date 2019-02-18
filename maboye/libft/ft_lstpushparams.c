/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushparams.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 02:19:05 by maboye            #+#    #+#             */
/*   Updated: 2018/11/13 18:36:35 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstpushparams(int ac, char **av)
{
	t_list	*temp;
	int		i;

	temp = 0;
	if (!ac)
		return (0);
	i = -1;
	while (++i < ac)
		ft_lstpushfront(&temp, av[i]);
	return (temp);
}
