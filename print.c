/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 19:29:40 by maboye            #+#    #+#             */
/*   Updated: 2019/02/10 12:43:27 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		term_size(int fd)
{
	struct winsize	size;

	ioctl(fd, TIOCGWINSZ, &size);
	return (size.ws_col);
}

void			ft_padding(int nb)
{
	write(1, "                                                         ", nb);
}

void			print_color(struct stat elem, char *str, int flags)
{
	if (flags & G_FLAG)
	{
		if (S_ISDIR(elem.st_mode))
			ft_printf("\033[1;34m%s\033[0m", str);
		else if (S_ISBLK(elem.st_mode))
			ft_printf("\033[34;46m%s\033[0m", str);
		else if (S_ISCHR(elem.st_mode))
			ft_printf("\033[34;43m%s\033[0m", str);
		else if (S_ISLNK(elem.st_mode))
			ft_printf("\033[1;35m%s\033[0m", str);
		else
			ft_putstr(str);
	}
	else
		ft_printf("%s", str);
}

void			print_column(void **stock, int size, int args, int flags)
{
	int			i;
	int			j;
	int			nb_line;
	int			nb_col;
	struct stat	elem;

	nb_col = (int)(term_size(STDOUT_FILENO) / size - 1);
	nb_line = (int)(args / nb_col + 1);
	j = -1;
	while (++j < nb_line)
	{
		i = -1;
		while (stock[++i])
		{
			stat(((t_list*)stock[i])->content, &elem);
			if (i % nb_line == j)
			{
				print_color(elem, ((t_list*)stock[i])->data, flags);
				stock[i + 1] ? ft_padding(1 + size
				- ((t_list*)stock[i])->size) : 0;
			}
		}
		ft_putchar('\n');
	}
}

void			print_list(void **stock, int flags)
{
	int			i;
	struct stat	elem;

	i = -1;
	while (stock[++i])
	{
		if (flags & G_FLAG)
		{
			stat(((t_list*)stock[i])->content, &elem);
			print_color(elem, ((t_list*)stock[i])->data, flags);
			ft_putchar('\n');
		}
		else
			ft_printf("%s\n", ((t_list*)stock[i])->data);
	}
}
