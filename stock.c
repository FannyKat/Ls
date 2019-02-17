#include "my_ls.h"

void			stock_dir(char *path, t_list *dir)
{
	struct dirent	*current;
	DIR*		curr_dir;
	t_list		*head;

	current = NULL;
	curr_dir = opendir(path);
	head = dir;
	path = ft_strjoin(path, "/");
	while ((current = readdir(curr_dir)) != NULL)
	{
		dir->content = ft_strdup(path);
		dir->content = ft_strjoin(path, current->d_name);
		dir->data = ft_strdup(current->d_name);
		dir->next = ft_xlstadd(NULL);
		dir = dir->next;
	}
	dir = head;
	closedir(curr_dir);
}

void			stock_data(int flags, char *path, t_list *files)
{
	(void)flags;
	files->data = ft_strdup(path);
	files->next = ft_xlstadd(NULL);
}

void			stock_params(int j, int flags, char **av, t_list *dir, t_list *files)
{
	struct stat	fd;
	int		i;
	int		cpt;

	i = 1;
	cpt = 0;
	stat(av[i], &fd);
	while (j-- > 1)
	{
		if (isdir(av[i]))
		{
			cpt++;
			stock_dir(av[i], dir);
			if (cpt == 1 && av[i + 1] != NULL && files->data == NULL)
				printf("%s:\n", av[i]);
			if ((av[i + 1] == NULL && cpt > 1) || files->data != NULL)
				printf("\n%s:\n", av[i]);
			if (flags & FLAG_L)
				block_bytes(flags, dir);
			sort(dir, flags);	
			if (flags & FLAG_T)
				time_sort(flags, dir);
			print_list(flags, dir);
			i++;	
			continue ;
		}
		i++;
	}
}
