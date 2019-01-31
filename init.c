#include "ls.h"

void				error(char	*str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

char				*get_name(char *av)
{
	char			*str;
	int				i;
	int				j;

	j = 0;
	i = ft_strlen(av);
	while (i > 0 && av[i] != '/')
		i--;
	i = av[i] == '/' ? i + 1 : i;
	str = ft_strdup(av + i);
	return (str);
}

char				*get_time(char *av)
{
	av = ft_strsub(av, 4, ft_strlen(av) - (4 + 9));
	return (av);
}

void 				*get_mode(mode_t fd)
{ 
	printf("%s", S_IRUSR & (fd) ? "r" : "-");
	printf("%s", S_IWUSR & (fd) ? "w" : "-");
	printf("%s", S_IXUSR & (fd) ? "x" : "-");
	printf("%s", S_IRGRP & (fd) ? "r" : "-");
	printf("%s", S_IWGRP & (fd) ? "w" : "-");
	printf("%s", S_IXGRP & (fd) ? "x" : "-");
	printf("%s", S_IROTH & (fd) ? "r" : "-");
	printf("%s", S_IWOTH & (fd) ? "w" : "-");
	printf("%s ", S_IXOTH & (fd) ? "x " : "- ");
}

void 				fd_inspect(char *av, int size)
{
	struct stat 	fd;
	struct passwd	*getuid;
	struct group	*getgid;

	stat(av, &fd);
	getuid = getpwuid(fd.st_uid);
	getgid = getgrgid(fd.st_gid);
	if (size)
	{
		printf("%s", S_ISDIR (fd.st_mode) ? "d" : "-");
		get_mode(fd.st_mode);
		printf("%u ", fd.st_nlink);
		printf("%s ", getuid->pw_name);
		printf("%s ", getgid->gr_name);
		printf("%lld ", fd.st_size);
		printf("%s ", get_time(ctime(&fd.st_mtime)));
		printf("%s\n", get_name(av));
	}
}

int 				isdir(char *name)
{
	struct stat 	buf;

	stat(name, &buf);

		return ((buf.st_mode & S_IFMT) == S_IFDIR);
}

void				stock_file(char *path, DIR *dir, int ac, t_list *file)
{
	struct dirent	*current;
	t_list			*begin;

	begin = file;
	while ((current = readdir(dir)) != NULL)
	{
		file->content = ft_strdup(path);
		file->data = ft_strdup(current->d_name);
		file->next = ft_xlstadd(NULL);
		file = file->next;
	}
	file = begin;
}

void					block_bytes(t_list *file, t_list *begin)
{
		struct stat 	fd;
		t_data			bytes;

		bytes.total = 0;
		while (file->next)
		{
			stat(file->data, &fd);
			bytes.total += fd.st_blocks;
			file = file->next;
		}
		file = begin;
		printf("total %lld\n", bytes.total);
}

int					is_notdot(t_list *file)
{
	char			*tmp;
	int				size;
	struct stat		fd;

	stat(file->content, &fd);
	tmp = ft_strdup(file->data);
	size = ft_strlen(tmp);
	if (S_ISDIR(fd.st_mode) && tmp[0] != '.')
		if (size != 1 || tmp[1] != '.')
			return (1);
	return (0);
}

void				check_subdir(t_list *file, DIR *dir, int ac)
{
	t_list			*begin;
	

	begin = file;
	while (file->next)
	{
		if (is_notdot(file))
		{
			//stock pos of subdir
			printf("\n");
			printf("%s:\n", file->content);
			dir = opendir(file->content);
			stock_file(file->content, dir, ac, file);
			block_bytes(file, begin);
			while (file->next)
			{
				file->content = ft_strjoin(file->content, "/");
				file->content = ft_strjoin(file->content, file->data);
				fd_inspect(file->content, ac);
				file = file->next;
			}
			file = begin;
		}
		file = file->next;
	}
	file = begin;
	file = //pos of subdir
	check_subdir(file, dir, ac);
}

int					main(int ac, char **av)
{
	struct dirent* 	current;
	struct stat		fd;
	DIR*			dir;
	t_list			*file;
	t_list			*begin;
	int				i = 1;
	int				j;

	stat(av[i], &fd);
	file = ft_xlstadd(NULL);
	begin = file;
	j = ac;
	//	fd_inspect(current->d_name, ac);
	while (j-- > 1)
	{
		if (isdir(av[i]))
		{
			dir = opendir(av[i]);
			stock_file(av[i], dir, ac, file);
			block_bytes(file, begin);
			while (file->next)
			{
				file->content = ft_strjoin(av[i], "/");
				file->content = ft_strjoin(file->content, file->data);
				fd_inspect(file->content, ac);
				file = file->next;
			}
			file = begin;
			closedir(dir);
			check_subdir(file, dir, ac);
			i++;
			continue ;
		}
		fd_inspect(av[i], ac);
		i++;
	}
	return (0);
}
