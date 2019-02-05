#include "my_ls.h"

void				*error(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}	

void				stock_file(char *path, DIR *dir, t_list *file)
{
	struct dirent		*current;
	t_list			*begin;

	begin = file;
	while ((current = readdir(dir)) != NULL)
	{
		file->content = ft_strdup(path);
		file->data = ft_strdup(current->d_name);
	printf("%s\n", file->data);
		file->next = ft_xlstadd(NULL);
		file = file->next;
	}
	file = begin;
}

int 				isdir(char *name)
{
	struct stat 		buf;

	lstat(name, &buf);
	return ((buf.st_mode & S_IFMT) == S_IFDIR);
}

int					is_notdot(t_list *file)
{
	char				*tmp;
	int				size;
	struct stat			fd;

	stat(file->content, &fd);
	tmp = ft_strdup(file->data);
	size = ft_strlen(tmp);
	if (S_ISDIR(fd.st_mode) && tmp[0] != '.')
		if (size != 1 || tmp[1] != '.')
			return (1);
	return (0);
}

int					main(int ac, char **av)
{
	struct stat			fd;
	DIR*				dir;
	t_list				*file;
	int				i = 1;
	int				j;

	stat(av[i], &fd);
	file = ft_xlstadd(NULL);
	j = ac;
	while (j-- > 1)
	{
		if (isdir(av[i]))
		{
			dir = opendir(av[i]);
			check_dir(file, av[i], ac, dir);
			i++;
			continue ;
		}
		inspect_file(av[i], ac);
		i++;
	}
	return (0);
}
