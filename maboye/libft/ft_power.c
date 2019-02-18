/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 22:52:22 by maboye            #+#    #+#             */
/*   Updated: 2018/11/23 06:48:49 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float		ft_power(int nb, int po)
{
	float		result;

	if (po == 0)
		return (1);
	result = ft_power(nb, po / 2);
	if (po % 2 == 0)
		return (result * result);
	else
		return (po > 0 ? nb * result * result : (result * result) / nb);
}
