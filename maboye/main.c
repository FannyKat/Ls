/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 02:19:15 by maboye            #+#    #+#             */
/*   Updated: 2019/02/09 00:31:28 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			error(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

static int		parsing(int *i, int ac, char **av, int src)
{
	while (++(*i) < ac && av[*i][0] == '-' && av[*i][1])
	{
		if (av[*i][1] == '-')
		{
			(*i)++;
			return (0);
		}
		src += check_flags(av[*i], src);
	}
	(src & C_FLAG) && !isatty(STDOUT_FILENO) ? src -= C_FLAG : 0;
	return (src);
}

static void		stock_args(int i, char **av, t_list *f_data)
{
	t_list		*head;

	head = f_data;
	while (av[i])
	{
		f_data->content = ft_strdup(av[i]);
		f_data->next = ft_lstaddelem(NULL);
		f_data = f_data->next;
		i++;
	}
	f_data = head;
}

static void		handle_file(t_list *f_data)
{
	t_list		*head;
	t_list		*next;
	struct stat	elem;

	head = f_data;
	while (f_data->next)
	{
		next = f_data->next;
		stat(next->content, &elem);
		if (S_ISREG(elem.st_mode))
		{
			f_data->next = next->next;
			ft_printf("%s\n", next->content);
			ft_lstdelone(next, 0);
			f_data->next ? 0 : ft_putchar('\n');
		}
		else
			f_data = f_data->next;
	}
	f_data = head;
}

int				main(int ac, char **av)
{
	t_list		*f_data;
	t_list		*stock;
	int			i;
	int			lst_size;
	int			flags;

	i = 0;
	flags = 0;
	flags = parsing(&i, ac, av, flags);
	f_data = ft_lstaddelem(NULL);
	stock = ft_lstaddelem(NULL);
	sort_av(av);
	stock_args(i, av, f_data);
	handle_file(f_data);
	i == ac ? ft_ls(f_data, ".", flags) : 0;
	lst_size = ft_lstsize(f_data);
	while (f_data->next && i != ac)
	{
		lst_size == 2 ? 0 : ft_printf("%s:\n", f_data->content);
		ft_ls(stock, f_data->content, flags);
		(f_data->next)->next ? ft_printf("\n") : 0;
		f_data = f_data->next;
	}
	//ac - i ? ft_lstdel(f_data, 0) : 0;
	return (0);
}
