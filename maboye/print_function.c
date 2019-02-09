/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 19:29:40 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 13:27:25 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_padding(int nb)
{
	write(1, "                                                         ", nb);
}

void			print_column(void **stock, int size, int args)
{
	int		i;
	int		j;
	int		nb_line;
	int		nb_col;

	nb_col = term_size(STDOUT_FILENO) / size - 1;
	nb_line = args / nb_col + 1;
	j = -1;
	while (++j < nb_line)
	{
		i = -1;
		while (stock[++i])
		{
			if (i % nb_line == j)
			{
				ft_putstr(((t_list*)stock[i])->data);
				stock[i + 1] ? ft_padding(1 + size
				- ft_strlen(((t_list*)stock[i])->data)) : 0;
			}
		}
		ft_putchar('\n');
	}
}

void			print_list(void **stock)
{
	int		i;

	i = -1;
	while (stock[++i])
		ft_printf("%s\n", ((t_list*)stock[i])->data);
}
