/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 03:21:18 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 13:27:23 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			sort_av(char **av)
{
	char	*stock;
	int		size;
	int		x;
	int		y;

	size = -1;
	while (av[++size])
		;
	y = 0;
	while (++y < size)
	{
		x = 0;
		while (++x < size - 1)
			if (ft_strcmp(av[x + 1], av[x]) < 0)
			{
				stock = av[x + 1];
				av[x + 1] = av[x];
				av[x] = stock;
			}
	}
}

void			sort_stock(void **av)
{
	void	*stock;
	int		size;
	int		x;
	int		y;

	size = -1;
	while (av[++size])
		;
	y = 0;
	while (++y < size)
	{
		x = -1;
		while (++x < size - 1)
			if (ft_strcmp(((t_list*)av[x + 1])->data,
				((t_list*)av[x])->data) < 0)
			{
				stock = av[x + 1];
				av[x + 1] = av[x];
				av[x] = stock;
			}
	}
}

static int		get_time(char *path)
{
	struct stat		elem;

	stat(path, &elem);
	return (elem.st_mtime);
}

void			sort_time(void **av)
{
	void	*stock;
	int		size;
	int		x;
	int		y;

	size = -1;
	while (av[++size])
		;
	y = 0;
	while (++y < size)
	{
		x = -1;
		while (++x < size - 1)
			if (get_time(((t_list*)av[x + 1])->content)
				- get_time(((t_list*)av[x])->content) > 0)
			{
				stock = av[x + 1];
				av[x + 1] = av[x];
				av[x] = stock;
			}
	}
}
