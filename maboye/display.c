/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 05:04:07 by maboye            #+#    #+#             */
/*   Updated: 2019/02/18 17:06:48 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_mode(mode_t fd)
{
	write(1, (S_IRUSR & fd) ? "r" : "-", 1);
	write(1, (S_IWUSR & fd) ? "w" : "-", 1);
	write(1, (S_IXUSR & fd) ? "x" : "-", 1);
	write(1, (S_IRGRP & fd) ? "r" : "-", 1);
	write(1, (S_IWGRP & fd) ? "w" : "-", 1);
	write(1, (S_IXGRP & fd) ? "x" : "-", 1);
	write(1, (S_IROTH & fd) ? "r" : "-", 1);
	write(1, (S_IWOTH & fd) ? "w" : "-", 1);
	write(1, (S_IXOTH & fd) ? "x " : "- ", 2);
}

static char		*get_mode(struct stat elem, char *path)
{
	char	*str;

	str = NULL;
	S_ISBLK(elem.st_mode) ? write(1, "b", 1) : 0;
	S_ISCHR(elem.st_mode) ? write(1, "c", 1) : 0;
	S_ISDIR(elem.st_mode) ? write(1, "d", 1) : 0;
	if (S_ISLNK(elem.st_mode))
	{
		readlink(path, str = ft_strnew(elem.st_size), elem.st_size);
		write(1, "l", 1);
	}
	S_ISSOCK(elem.st_mode) ? write(1, "s", 1) : 0;
	S_ISFIFO(elem.st_mode) ? write(1, "p", 1) : 0;
	S_ISREG(elem.st_mode) ? write(1, "-", 1) : 0;
	return (str);
}

static void		stock_info(t_data *info, void **addr)
{
	int				i;
	struct stat		elem;
	struct passwd	*getuid;
	struct group	*getgid;
	int				len;

	len = 0;
	i = -1;
	info->uid = len;
	info->gid = len;
	while (addr[++i])
	{
		lstat(((t_list*)addr[i])->content, &elem);
		info->weight = info->weight < elem.st_size ?
			elem.st_size : info->weight;
		info->link = info->link < elem.st_nlink ? elem.st_nlink : info->link;
		getuid = getpwuid(1);
		getgid = getgrgid(1);
		len = ft_strlen(getuid->pw_name);
		info->uid = info->uid < len ? len : info->uid;
		len = ft_strlen(getgid->gr_name);
		info->gid = info->gid < len ? len : info->gid;
	}
	info->weight = int_len(info->weight);
	info->link = int_len(info->link);
}

static void		print_padding(struct stat fd, t_data *info,
				struct passwd *getuid, struct group *getgid)
{
	int		flags;

	flags = info->flags;
	ft_padding(info->link - int_len(fd.st_nlink));
	ft_printf("%d ", (int)fd.st_nlink);
	if (!(flags & FLAG))
	{
		ft_padding(info->uid - ft_strlen(getuid->pw_name));
		ft_printf("%s ", getuid->pw_name);
	}
	ft_padding(info->gid - ft_strlen(getgid->gr_name));
	ft_printf("%s ", getgid->gr_name); 
	ft_padding(info->weight - int_len(fd.st_size));
	ft_printf("%d ", (int)fd.st_size);
}

void			long_listing(void **addr, int flags, int i)
{
	struct stat		fd;
	struct passwd	*getuid;
	struct group	*getgid;
	char			*str;
	t_data			*info;

	if (!(info = malloc(sizeof(t_data))))
		return ;
	stock_info(info, addr);
	info->flags = flags;
	while (addr[++i])
	{
		lstat(((t_list*)addr[i])->content, &fd);
		getuid = getpwuid(fd.st_uid);
		getgid = getgrgid(fd.st_gid);
		str = get_mode(fd, ((t_list*)addr[i])->content);
		print_mode(fd.st_mode);
		print_padding(fd, info, getuid, getgid);
		handle_option(fd, flags);
		print_color(fd, ((t_list*)addr[i])->data, flags);
		S_ISLNK(fd.st_mode) ? ft_printf(" -> %s\n", str) : ft_putchar('\n');
		ft_strdel(&str);
	}
	ft_memdel((void**)(&info));
}
