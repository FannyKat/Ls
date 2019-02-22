#include "my_ls.h"

void			print_list(int flags, t_list *files)
{
	struct stat	fd;
	t_list		*head;

	head = files;
	while (files->next)
	{
		if (!(flags & FLAG_A) && isdot(files->data))
		{
			files = files->next;
			continue ;
		}
		if (flags & FLAG_L)
			inspect_file(flags, files->content);
		if (!(flags & FLAG_L))
		{
			lstat(files->content, &fd);
			put_colors(fd, files->data, flags);
		}
		files = files->next;
	}
	files = head;
}

void			list_contents(int flags, int i, int j, char **av)
{
	t_list		*files;
	t_list		*head;
	t_list		*dir;
	int			cpt;

	cpt = 0;
	files = ft_xlstadd(NULL);
	dir = ft_xlstadd(NULL);
	while (i < j)
	{
		if (!isdir(av[i]))
		{
			stock_data(av[i], files);
			if (cpt == 0)
				head = files;
			files = files->next;
			cpt++;		
		}
		i++;
	}
	(cpt > 0) ? files = head : 0;
	(cpt > 0) ? walking_files(flags, files) : 0;
	stock_params(j, flags, av, dir, files);
}

int			main(int ac, char **av)
{
	int		j;
	int		i;
	int		flags;

	i = 1;
	j = ac;
	flags = check_dash(&i, av);
	(flags == 0) ? i = 1 : 0;
	list_contents(flags, i, j, av);	
	return (0);
}
