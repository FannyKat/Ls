#include "my_ls.h"

void			*error(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

int 			isdir(char *path)
{
	struct stat 	buf;

	lstat(path, &buf);
	return ((buf.st_mode & S_IFMT) == S_IFDIR);
}

int			isdot(char *dot)
{
	int		cpt;

	cpt = 0;
	(*dot++ == '.') ? cpt++ : 0;
	(*dot == '.') ? cpt++ : 0;
	return ((cpt == 1 || cpt == 2 ) ? 1 : 0);
}

void			put_colors(struct stat fd, char *path, int flags)
{
	char		*str;

	S_ISDIR (fd.st_mode) ? printf("\033[1;34m%s\033[0m\n", get_name(path)) : 0; 
	if (S_ISLNK (fd.st_mode))
	{
		if (flags & FLAG_L)
		{
			readlink(path, str = ft_strnew(fd.st_size), fd.st_size);
	   		printf("\033[1;35m%s\033[0m -> %s\n", get_name(path), str); 
		}
		else
	   		printf("\033[1;35m%s\033[0m\n", get_name(path)); 
	}
	if (S_ISREG (fd.st_mode))
	{
		if (S_IXUSR & fd.st_mode || S_IXGRP & fd.st_mode || S_IXOTH & fd.st_mode)
			printf("\033[38;5;124m%s\033[0m\n", path);
		else
			printf("%s\n", get_name(path));
	}
	S_ISCHR (fd.st_mode) ? printf("\033[34;43m%s\033[0m\n", get_name(path)) : 0;
	S_ISBLK (fd.st_mode) ? printf("\033[34;46m%s\033[0m\n", get_name(path)) : 0;
}

void			walking_files(int flags, t_list *files)
{
	t_list		*head;
	struct stat	fd;

	head = files;
	sort(files, flags);
	while (files->next)
	{
		lstat(files->content, &fd);
		if (errno == EACCES)
			printf("ft_ls: %s: Permission denied\n", files->data);
		if (!(flags & FLAG_A) && isdot(files->data))
		{
			files = files->next;
			continue ;
		}
		if ((flags & FLAG_L) && !isdir(files->data))
			inspect_file(flags, files->data);
		if (!(flags & FLAG_L) && !isdir(files->data))
			printf("%s\n", get_name(files->data));
		files = files->next;
	}
	files = head;
}
