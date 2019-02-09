/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:30:28 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 23:33:07 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			block_bytes(t_list *file, int flags)
{
	struct stat		fd;
	t_data			bytes;
	t_list			*begin;

	begin = file;
	bytes.total = 0;
	while (file->next)
	{
		stat(file->content, &fd);
		if (!(flags & A_FLAG) && is_dot(file->data))
		{
			file = file->next;
			continue ;
		}
		bytes.total += fd.st_blocks;
		file = file->next;
	}
	file = begin;
	ft_printf("total %d\n", (int)bytes.total);
}

int				check_flags(char *str, int src)
{
	int		i;
	int		flags;

	flags = 0;
	i = 0;
	while (str[++i])
	{
		if (str[i] == 'a' && !(src & A_FLAG))
			flags += A_FLAG;
		if (str[i] == 'C' && !(src & C_FLAG))
			flags += C_FLAG;
		if (str[i] == 'l' && !(src & L_FLAG))
			flags += L_FLAG;
		if (str[i] == 'R' && !(src & R_FLAG))
			flags += R_FLAG;
		if (str[i] == 'r' && !(src & REV_FLAG))
			flags += REV_FLAG;
		if (str[i] == 't' && !(src & T_FLAG))
			flags += T_FLAG;
	}
	return (flags);
}

void			ft_free_table(void **table)
{
	int	x;

	x = -1;
	while (table[++x])
	{
		free(table[x]);
		table[x] = NULL;
	}
	free(table);
	table = NULL;
}

int				is_dot(char *str)
{
	return (*str == '.' ? 1 : 0);
}

int				term_size(int fd)
{
	struct winsize	size;

	ioctl(fd, TIOCGWINSZ, &size);
	return (size.ws_col);
}
