/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:55:31 by maboye            #+#    #+#             */
/*   Updated: 2019/02/09 00:17:18 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		get_size(t_list *f_data)
{
	t_list	*begin;
	size_t	size;

	begin = f_data;
	size = 0;
	while (f_data->next)
	{
		size = size < f_data->size ? f_data->size : size;
		f_data = f_data->next;
	}
	f_data = begin;
	return ((int)size);
}

static void		l_handler(t_list *f_data, int flags)
{
	t_list	*begin;

	begin = f_data;
	block_bytes(f_data, flags);
	while (f_data->next)
	{
		long_listing(f_data->content);
		f_data = f_data->next;
	}
	f_data = begin;
}

static void		**ft_stockaddr(t_list *list)
{
	int		i;
	int		lst_len;
	void	**stock;
	t_list	*begin;

	lst_len = ft_lstsize(list);
	stock = malloc(sizeof(void**) * lst_len);
	begin = list;
	i = 0;
	while (list->next)
	{
		stock[i++] = &(*list);
		list = list->next;
	}
	stock[i] = 0;
	list = begin;
	return (stock);
}

static void		flags_handler(t_list *f_data, void **stock, int flags)
{
	void	*tmp;
	int		size;
	int		i;

	if (flags & REV_FLAG)
	{
		size = -1;
		while (stock[++size])
			;
		i = -1;
		while (++i < size--)
		{
			tmp = stock[size];
			stock[size] = stock[i];
			stock[i] = tmp;
		}
	}
	if (flags & C_FLAG)
		print_column(stock, get_size(f_data), ft_lstsize(f_data));
	if (flags & L_FLAG)
		l_handler(f_data, flags);
}

void			ft_ls(t_list *f_data, char *path, int flags)
{
	t_list	*f_path;
	void	**stock;

	f_path = stock_list(f_data, path, flags);
	if (!f_path || !f_data)
		return ;
	stock = ft_stockaddr(f_data);
	sort_stock(stock);
	(flags & T_FLAG) ? sort_time(stock) : 0;
	flags_handler(f_data, stock, flags);
	if (!(flags & C_FLAG) && !(flags & L_FLAG))
		print_list(stock);
	if (flags & R_FLAG)
		while (f_path->next)
		{
			ft_printf("\n\n%s:\n", f_path->content);
			ft_ls(f_data, f_path->content, flags);
			f_path = f_path->next;
		}
	ft_lstdel(f_path, 0);
}
