/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 07:01:24 by maboye            #+#    #+#             */
/*   Updated: 2019/02/18 14:50:14 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_ascii_partition(void **add, int start, int size)
{
	int		i;
	int		j;
	int		pivot;

	i = start - 1;
	j = start - 1;
	pivot = size - 1;
	if (size - start == 2)
	{
		if (ft_strcmp(((t_list*)add[start])->data,
				((t_list*)add[size - 1])->data) > 0)
			ft_swap(&add[start], &add[size - 1]);
		return (0);
	}
	while (i < size - 1 && ++j < size - 1)
		if (ft_strcmp(((t_list*)add[j])->data, ((t_list*)add[pivot])->data) < 0)
			ft_swap(&add[++i], &add[j]);
	ft_swap(&add[i + 1], &add[pivot]);
	return (i + 1);
}

static int		get_time(char *path)
{
	struct stat		elem;

	lstat(path, &elem);
	return (elem.st_mtime);
}

static void		ft_time_loop(void **add, int start, int size, int *i)
{
	int	j;
	int	diff;
	int	pivot;

	j = start - 1;
	pivot = size - 1;
	while (*i < size - 1 && ++j < size - 1)
	{
		diff = get_time(((t_list*)add[j])->content)
			- get_time(((t_list*)add[pivot])->content);
		if (diff > 0)
			ft_swap(&add[++(*i)], &add[j]);
		else if (!diff)
			if (ft_strcmp(((t_list*)add[j])->data, ((t_list*)add[pivot])->data) < 0)
				ft_swap(&add[++(*i)], &add[j]);
	}
	ft_swap(&add[*i + 1], &add[pivot]);
}

static int		ft_time_partition(void **add, int start, int size)
{
	int		i;
	int		diff;

	i = start - 1;
	if (size - start == 2)
	{
		diff = get_time(((t_list*)add[start])->content)
			- get_time(((t_list*)add[size - 1])->content);
		if (diff < 0)
			ft_swap(&add[start], &add[size - 1]);
		else if (!diff)
			if (ft_strcmp(((t_list*)add[start])->data, ((t_list*)add[size - 1])->data) < 0)
				ft_swap(&add[start], &add[size - 1]);
		return (0);
	}
	ft_time_loop(add, start, size, &i);
	return (i + 1);
}

int				ft_ls_quicksort(void **add, int start, int size, int choose)
{
	int		j;

	if (start < size - 1)
	{
		if (choose)
			j = ft_time_partition(add, start, size);
		else
			j = ft_ascii_partition(add, start, size);
		ft_ls_quicksort((&add[start]), 0, j, choose);
		ft_ls_quicksort((&add[j + 1]), 0, (size - j - 1), choose);
	}
	return (0);
}
