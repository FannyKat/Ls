#include "my_ls.h"

void			block_bytes(int flags, t_list *file)
{
	struct stat 	fd;
	t_data			bytes;
	t_list			*begin;

	begin = file;
	bytes.total = 0;
	while (file->next)
	{
		stat(file->content, &fd);
		if (!(flags & FLAG_A) && isdot(file->data))
		{
			file = file->next;
			continue ;
		}
		bytes.total += fd.st_blocks;
		file = file->next;
	}
	file = begin;
	my_printf("total %d\n", bytes.total);
}

char			*get_name(char *av)
{
	char		*str;
	int		i;

	i = ft_strlen(av);
	while (i > 0 && av[i] != '/')
		i--;
	i = av[i] == '/' ? i + 1 : i;
	str = ft_strdup(av + i);
	return (str);
}

char			*get_date(char *av)
{
	av = ft_strsub(av, 4, ft_strlen(av) - (4 + 9));
	return (av);
}

void 			get_mode(mode_t fd)
{ 
	write(1, S_IRUSR & fd ? "r" : "-", 1);
	write(1, S_IWUSR & fd ? "w" : "-", 1);
	if (S_IXUSR & fd)
		write(1, S_ISVTX & fd ? "s" : "x", 1);
	else
		write(1, S_ISVTX & fd ? "S" : "-", 1);
	write(1, S_IRGRP & fd ? "r" : "-", 1);
	write(1, S_IWGRP & fd ? "w" : "-", 1);
	if (S_IXGRP & fd)
		write(1, S_ISVTX & fd ? "s" : "x", 1);
	else
		write(1, S_ISVTX & fd ? "S" : "-", 1);
	write(1, S_IROTH & fd ? "r" : "-", 1);
	write(1, S_IWOTH & fd ? "w" : "-", 1);
	if (S_IXOTH & fd)
		write(1, S_ISGID & fd ? "t " : "x ", 2);
	else
		write(1, S_ISGID & fd ? "T " : "- ", 2);
}

void 			inspect_file(int flags, char *path)
{
	struct stat 	fd;
	struct passwd	*getuid;
	struct group	*getgid;

	lstat(path, &fd);
	getuid = getpwuid(fd.st_uid);
	getgid = getgrgid(fd.st_gid);
	S_ISREG (fd.st_mode) ? write(1, "-", 1) : 0;
	S_ISBLK (fd.st_mode) ? write(1, "b", 1) : 0;
	S_ISCHR (fd.st_mode) ? write(1, "c", 1) : 0;
	S_ISDIR (fd.st_mode) ? write(1, "d", 1) : 0;
	S_ISFIFO (fd.st_mode) ? write(1, "p", 1) : 0;
	S_ISLNK (fd.st_mode) ? write(1, "l", 1) : 0;
	S_ISSOCK (fd.st_mode) ? write(1, "s", 1) : 0;
	get_mode(fd.st_mode);
	my_printf("%d ", fd.st_nlink);
	my_printf("%s ", getuid->pw_name);
	my_printf("%s ", getgid->gr_name);
	my_printf("%d ", fd.st_size);
	my_printf("%s ", get_date(ctime(&fd.st_mtime)));
	put_colors(fd, path, flags);
}
