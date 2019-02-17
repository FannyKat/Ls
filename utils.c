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

void			walking_files(int flags, t_list *files)
{
	t_list		*head;

	head = files;
	sort(files, flags);
	while (files->next)
	{
		if (!(flags & FLAG_A) && isdot(files->data))
		{
			files = files->next;
			continue ;
		}
		if ((flags & FLAG_L) && !isdir(files->data))
			inspect_file(files->data);
		if (!(flags & FLAG_L) && !isdir(files->data))
			printf("%s\n", get_name(files->data));
		files = files->next;
	}
	files = head;
}
/*
void				walking_dir(int flags, t_list *files)
{
	t_list			*head;

	head = files;
	while (files->next)
	{
		if (!(flags & FLAG_A) && isdot(files->data))
		{
			files = files->next;
			continue ;
		}
		if ((flags & FLAG_L) && isdir(files->content))
			inspect_file(files->content);
		if (!(flags & FLAG_L) && isdir(files->content))
			printf("\033[1;34m%s\033[0m\n", get_name(files->data));
		files = files->next;
	}
	files = head;
}*/
