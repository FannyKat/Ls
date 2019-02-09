#include "my_ls.h"

void					stock_dir(char *path, t_list *dir)
{
	struct dirent		*current;
	DIR*				curr_dir;
	t_list				*head;

	current = NULL;
	curr_dir = opendir(path);
	head = dir;

	while ((current = readdir(curr_dir)) != NULL)
	{
		dir->content = ft_strdup(path);
		dir->data = ft_strdup(current->d_name);
		dir->next = ft_xlstadd(NULL);
		dir = dir->next;
	}
	dir = head;
	closedir(curr_dir);
}

void					stock_data(char *path, t_list *av)
{
	av->content = ft_strdup(path);
	av->next = ft_xlstadd(NULL);
	av = av->next;
}

void					stock_params(int j, char **av, t_list *params, t_list *dir)
{
	struct stat			fd;
	int					i = 1;
	t_list				*head;

	stat(av[i], &fd);
	head = dir;
	while (j-- > 1)
	{
		if (isdir(av[i]))
		{
			stock_dir(av[i], dir);
			i++;
			printf("\n%s:\n", dir->content);
			print_list(dir);
			continue ;
		}	
		i++;
	}
}
