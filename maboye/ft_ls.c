/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:55:31 by maboye            #+#    #+#             */
/*   Updated: 2019/02/18 14:13:05 by maboye           ###   ########.fr       */
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

static void		flags_handler(t_list *f_data, void **stock, int flags)
{
	int	list_len;

	list_len = ft_lstsize(f_data);
	if ((flags & C_FLAG) && !(flags & L_FLAG) && !(flags & FLAG))
		print_column(stock, get_size(f_data), list_len, flags);
	if (((flags & L_FLAG) || (flags & FLAG)) && !(flags & F_FLAG))
	{
		list_len == 1 ? 0 : block_bytes(f_data);
		long_listing(stock, flags, -1);
	}
}

static void		ft_free(void **s1, void **s2)
{
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	if (s2)
	{
		free(s2);
		s2 = NULL;
	}
}

void			ft_ls(t_list *f_data, char *path, int flags)
{
	t_list	*f_path;
	void	**f_stock;
	void	**p_stock;
	int		i;

	f_path = stock_list(f_data, path, flags);
	f_stock = ft_stockaddr(f_data, flags);
	p_stock = ft_stockaddr(f_path, flags);
	if (!f_path || !f_data)
	{
		ft_free(f_stock, p_stock);
		return ;
	}
	flags_handler(f_data, f_stock, flags);
	if (!(flags & C_FLAG) && !(flags & L_FLAG) && !(flags & FLAG))
		print_list(f_stock, flags);
	i = -1;
	if (flags & R_FLAG)
		while (p_stock[++i])
		{
			ft_printf("\n\n%s:\n", ((t_list*)p_stock[i])->content);
			ft_ls(f_data, ((t_list*)p_stock[i])->content, flags);
		}
	ft_free(f_stock, p_stock);
	//ft_lstdel(&f_path);
}
