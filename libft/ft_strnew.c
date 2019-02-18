/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:37:43 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 11:29:51 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*tmp;

	if (!(tmp = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	ft_bzero(tmp, size + 1);
	return (tmp);
}
