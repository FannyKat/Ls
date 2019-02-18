/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:43:39 by maboye            #+#    #+#             */
/*   Updated: 2019/02/18 14:17:56 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_sort_apply(void **addr, int flags)
{
	int		i;
	int		size;

	size = -1;
	while (addr[++size])
		;
	ft_ls_quicksort(addr, 0, size, 0);
	(flags & T_FLAG) && !(flags & U_FLAG) ? ft_ls_quicksort(addr, 0, size, 1) : 0;
	if (flags & REV_FLAG)
	{
		i = -1;
		while (++i < size--)
			ft_swap(&addr[size], &addr[i]);
	}
}

void			**ft_stockaddr(t_list *list, int flags)
{
	int		i;
	void	**stock;
	t_list	*begin;

	if (!list || !(stock = malloc(sizeof(void**) * ft_lstsize(list))))
		return (NULL);
	begin = list;
	i = 0;
	while (list->next)
	{
		stock[i++] = &(*list);
		list = list->next;
	}
	stock[i] = 0;
	ft_sort_apply(stock, flags);
	list = begin;
	return (stock);
}

static void		stock_info(t_list **f_data, t_list **f_path,
		struct dirent **pdirent, char *path)
{
	int		flags;

	flags = ft_atoi((*f_path)->content);
	if ((flags & DOT_FLAG) && is_dot((*pdirent)->d_name, 1))
		return ;
	if (!(flags & A_FLAG) && !(flags & DOT_FLAG)
		&& is_dot((*pdirent)->d_name, 0))
		return ;
	(*f_data)->data = ft_strdup((*pdirent)->d_name);
	(*f_data)->content = ft_strjoin(path, (*f_data)->data);
	(*f_data)->content_size = (*pdirent)->d_type;
	(*f_data)->size = (*pdirent)->d_namlen;
	if ((*f_data)->content_size == 4 && !is_dot((*f_data)->data, 0))
	{
		(*f_path)->content = (*f_data)->content;
		(*f_path)->data = (*f_data)->data;
		(*f_path)->next = ft_lstaddelem(ft_itoa(flags));
		(*f_path) = (*f_path)->next;
	}
	(*f_data)->next = ft_lstaddelem(NULL);
	(*f_data) = (*f_data)->next;
}

t_list			*stock_list(t_list *f_data, char *path, int flags)
{
	struct dirent	*pdirent;
	DIR				*p_dir;
	t_list			*f_path;
	t_list			*t_data;
	t_list			*t_path;

	if (!(f_path = ft_lstaddelem(ft_itoa(flags))))
		return (NULL);
	t_data = f_data;
	t_path = f_path;
	path = path[ft_strlen(path) - 1] != '/' ? ft_strjoin(path, "/") : path;
	p_dir = opendir(path);
	if (p_dir)
	{
		while ((pdirent = readdir(p_dir)) != NULL)
			stock_info(&t_data, &t_path, &pdirent, path);
		closedir(p_dir);
		return (f_path);
	}
	if (!(errno == ENOTDIR))
		ft_printf("ls: '%s': No such file or directory\n\n", path);
	ft_lstdelone(&f_path);
	return (NULL);
}
