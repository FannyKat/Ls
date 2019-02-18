/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 02:19:15 by maboye            #+#    #+#             */
/*   Updated: 2019/02/18 14:51:12 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		stock_args(int i, char **av, t_list *f_data)
{
	t_list		*head;

	if (!av || !f_data)
		return ;
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

static void		ft_tools(t_list **head, t_list **new)
{
	struct stat	elem;

	if (!head || !*head || !new || !*new)
		return ;
	stat((*head)->content, &elem);
	if (!S_ISDIR(elem.st_mode))
		ft_printf("%s\n\n", (*head)->content);
	else if (S_ISDIR(elem.st_mode))
	{
		(*new)->content = ft_strdup((*head)->content);
		(*new)->next = ft_lstaddelem(NULL);
		(*new) = (*new)->next;
	}
	else
		ft_printf("ft_ls: %s: No such file or directory\n", (*head)->content);
	(*head) = (*head)->next;
}

static t_list	*handle_file(t_list *f_data, int size)
{
	t_list		*new;
	t_list		*head;
	t_list		*begin;

	new = ft_lstaddelem(NULL);
	head = f_data;
	begin = new;
	while (--size)
		ft_tools(&head, &new);
	ft_lstdel(&head);
	return (begin);
}

static void		handle_args(t_list **f_data, int flags)
{
	void	**addr;
	t_list	*stock;
	int		x;
	int		len;

	if (!(stock = ft_lstaddelem(NULL)))
		return ;
	addr = ft_stockaddr(*f_data, flags);
	len = -1;
	while (addr[++len])
		;
	x = -1;
	while (addr[++x])
	{
		ft_printf("%s", ((t_list*)addr[x])->content);
		(flags & D_FLAG) ? ft_putchar('\n') : ft_putstr(":\n");
		!(flags & D_FLAG) ? ft_ls(stock,
			((t_list*)addr[x])->content, flags) : 0;
		x < len - 1 ? ft_putchar('\n') : 0;
	}
	ft_lstdel(&stock);
	free(addr);
	addr = NULL;
}

int				main(int ac, char **av)
{
	t_list		*f_data;
	int			i;
	int			flags;

	i = 0;
	flags = 0;
	flags = parsing(&i, ac, av, flags);
	if (!(f_data = ft_lstaddelem(NULL)))
		return (0);
	sort_av(av);
	stock_args(i, av, f_data);
	if (!(f_data = handle_file(f_data, ft_lstsize(f_data))))
		return (0);
	i == ac && !(flags & D_FLAG) ? ft_ls(f_data, ".", flags) : 0;
	i != ac ? handle_args(&f_data, flags) : 0;
	ft_lstdel(&f_data);
	return (0);
}
