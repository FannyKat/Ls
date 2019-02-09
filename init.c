#include "my_ls.h"

void					*error(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}	

int 					isdir(char *path)
{
	struct stat 		buf;

	lstat(path, &buf);
	return ((buf.st_mode & S_IFMT) == S_IFDIR);
}

int						is_notdot(t_list *file)
{
	char				*tmp;
	int					size;
	struct stat			fd;

	stat(file->content, &fd);
	tmp = ft_strdup(file->data);
	size = ft_strlen(tmp);
	if (S_ISDIR(fd.st_mode) && tmp[0] != '.')
		if (size != 1 || tmp[1] != '.')
			return (1);
	return (0);
}

int						isdot(char *dot)
{
	int					cpt;

	cpt = 0;
	(*dot++ == '.') ? cpt++ : 0;
	(*dot == '.') ? cpt++ : 0;
	return ((cpt == 1 || cpt == 2 ) ? 1 : 0);
}

void					print_list(t_list *files)
{
		t_list			*begin;

		begin = files;
		while (files->next)
		{
			if (isdot(files->data)) //!flags -a
					files = files->next;
			else
			{	
				printf("%s\n", get_name(files->data));
				files = files->next;
			}
		}
		files = begin;
}

int						main(int ac, char **av)
{
	t_list				*files;
	t_list				*dir;
	int					j;
	int					i;
	int					flags;

	i = 1;
	j = ac;
	files = ft_xlstadd(NULL);
	dir = ft_xlstadd(NULL);
	flags = check_dash(&i, av);
	while (i < j)
	{
		if (!isdir(av[i]))
		{
			stock_data(av[i], files);
			printf("%s\n", get_name(files->content));
		}
		i++;
	}
	//print_list(files);
	stock_params(j, av, files, dir);
/*	LFLAGS 
	inspect_file(av[i], ac);
	stock and print tlist files
								*/
	return (0);
}
