/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:43:39 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 23:32:49 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*make_path(char *path, struct dirent *pdirent)
{
	char	*ret;

	ret = ft_strdup(path);
	ret = ft_strfjoin(ret, pdirent->d_name);
	return (ret);
}

static void		stock_info(t_list **f_data, t_list **f_path,
		struct dirent **pdirent, char *path)
{
	int		flags;

	flags = ft_atoi((*f_path)->content);
	if (!(flags & A_FLAG) && is_dot((*pdirent)->d_name))
		return ;
	(*f_data)->content = make_path(path, *pdirent);
	(*f_data)->content_size = (*pdirent)->d_type;
	(*f_data)->data = ft_strdup((*pdirent)->d_name);
	(*f_data)->size = (*pdirent)->d_namlen;
	if ((*f_data)->content_size == 4 && !is_dot((*f_data)->data))
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

	f_path = ft_lstaddelem(ft_itoa(flags));
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
	return (NULL);
}
