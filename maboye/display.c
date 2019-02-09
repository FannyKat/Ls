/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 03:20:59 by fcatusse          #+#    #+#             */
/*   Updated: 2019/02/09 03:40:55 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*get_name(char *av)
{
	char	*str;
	int		i;

	i = ft_strlen(av);
	while (i > 0 && av[i] != '/')
		i--;
	i = av[i] == '/' ? i + 1 : i;
	str = ft_strdup(av + i);
	return (str);
}

static char		*get_time(char *av)
{
	av = ft_strsub(av, 4, ft_strlen(av) - (4 + 9));
	return (av);
}

static void		get_mode(mode_t fd)
{
	ft_printf("%s", S_IRUSR & (fd) ? "r" : "-");
	ft_printf("%s", S_IWUSR & (fd) ? "w" : "-");
	ft_printf("%s", S_IXUSR & (fd) ? "x" : "-");
	ft_printf("%s", S_IRGRP & (fd) ? "r" : "-");
	ft_printf("%s", S_IWGRP & (fd) ? "w" : "-");
	ft_printf("%s", S_IXGRP & (fd) ? "x" : "-");
	ft_printf("%s", S_IROTH & (fd) ? "r" : "-");
	ft_printf("%s", S_IWOTH & (fd) ? "w" : "-");
	ft_printf("%s ", S_IXOTH & (fd) ? "x " : "- ");
}

void			print_mode(struct stat fd)
{
	(fd.st_mode & S_IFMT) == S_IFBLK ? ft_printf("b") : 0;
	(fd.st_mode & S_IFMT) == S_IFCHR ? ft_printf("c") : 0;
	(fd.st_mode & S_IFMT) == S_IFDIR ? ft_printf("d") : 0; 
	(fd.st_mode & S_IFMT) == S_IFLNK ? ft_printf("l") : 0;
	(fd.st_mode & S_IFMT) == S_IFSOCK ? ft_printf("s") : 0;
	(fd.st_mode & S_IFMT) == S_IFIFO ? ft_printf("p") : 0;
	(fd.st_mode & S_IFMT) == S_IFREG ? ft_printf("-") : 0;

}

void			long_listing(char *path)
{
	struct stat		fd;
	struct passwd	*getuid;
	struct group	*getgid;

	stat(path, &fd);
	getuid = getpwuid(fd.st_uid);
	getgid = getgrgid(fd.st_gid);
	print_mode(fd);
	get_mode(fd.st_mode);
	ft_printf("%d ", (int)fd.st_nlink);
	ft_printf("%s ", getuid->pw_name);
	ft_printf("%s ", getgid->gr_name);
	ft_printf("%d ", (int)fd.st_size);
	ft_printf("%s ", get_time(ctime(&fd.st_mtime)));
	if (S_ISDIR(fd.st_mode))
		ft_printf("\033[1;34m%s\033[0m\n", get_name(path));
	else if (S_ISBLK(fd.st_mode))
		ft_printf("\033[34;46m%s\033[0m\n", get_name(path));
	else if (S_ISCHR(fd.st_mode))
		ft_printf("\033[34;43m%s\033[0m\n", get_name(path));
	else if (S_ISLNK(fd.st_mode))
		ft_printf("\033[1;35m%s\033[0m\n", get_name(path));
	else
		ft_printf("%s\n", get_name(path));
}
