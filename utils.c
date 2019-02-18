/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:30:28 by maboye            #+#    #+#             */
/*   Updated: 2019/02/18 14:12:47 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			block_bytes(t_list *file)
{
	struct stat		fd;
	t_data			bytes;
	t_list			*begin;

	begin = file;
	bytes.total = 0;
	while (file->next)
	{
		lstat(file->content, &fd);
		bytes.total += fd.st_blocks;
		file = file->next;
	}
	file = begin;
	ft_printf("total %d\n", (int)bytes.total);
}

void			error(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void			handle_option(struct stat fd, int flags)
{
	if (flags & U_FLAG)
	{
		write(1, ctime(&fd.st_atime) + 4,
			ft_strlen(ctime(&fd.st_atime) + 4) - 9);
	}
	else
		write(1, ctime(&fd.st_mtime) + 4,
			ft_strlen(ctime(&fd.st_mtime) + 4) - 9);
	ft_putchar(' ');
}

int				int_len(int nb)
{
	int		count;

	count = 0;
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count + 1);
}

int				is_dot(char *str, int choose)
{
	int	size;

	size = ft_strlen(str);
	if (choose)
	{
		if (!ft_strcmp(str, "."))
			return (1);
		if (!ft_strcmp(str, ".."))
			return (1);
		return (0);
	}
	return (*str == '.' ? 1 : 0);
}
