#include "my_ls.h"

void			stock_dir(char *path, t_list *dir)
{
	struct dirent	*current;
	DIR*			curr_dir;
	t_list			*head;

	current = NULL;
	curr_dir = opendir(path);
	head = dir;
	path = ft_strjoin(path, "/");
	if (curr_dir)
	{
		while ((current = readdir(curr_dir)) != NULL)
		{	
			dir->content = ft_strdup(path);
			dir->content = ft_strjoin(path, current->d_name);
			dir->size = current->d_type;
			dir->data = ft_strdup(current->d_name);
			dir->next = ft_xlstadd(NULL);
			dir = dir->next;
		}
		dir = head;
		closedir(curr_dir);
	}
	else
		(errno == EACCES) ? check_errno(path) : 0;
}

void			check_subdir(t_list *curr, t_list *subdir, int flags)
{
	while (curr->next)
	{
		if ((!(flags & FLAG_A) && isdot(curr->data)))
		{
			curr = curr->next;
			continue ;
		}
		if (curr->size == 4)
		{
			printf("\n%s:\n", curr->content);
			stock_dir(curr->content, subdir);
			sort(subdir, flags);
			print_list(flags, subdir);
			check_subdir(subdir, subdir, flags);
		}
		curr = curr->next;
	}
}

void			stock_data(char *path, t_list *files)
{
	printf("%s\n", path);
	files->data = ft_strdup(path);
	files->content = ft_strdup(path);
	files->size = 8;
	files->next = ft_xlstadd(NULL);
}

void			check_opt(int flags, t_list *dir)
{
	t_list		*subdir;
	
	subdir = ft_xlstadd(NULL);
	if (flags & FLAG_L)
		block_bytes(flags, dir);
	sort(dir, flags);	
	if (flags & FLAG_T)
		time_sort(flags, dir);
	print_list(flags, dir);
	if (flags & FLAG_R)
		check_subdir(dir, subdir, flags);
}

void			stock_params(int j, int flags, char **av, t_list *dir, t_list *files)
{
	struct stat	fd;
	int			i;
	int			cpt;

	i = 1;
	cpt = 0;
	stat(av[i], &fd);
	while (j-- > 1)
	{
		if (isdir(av[i]))
		{
			cpt++;
			stock_dir(av[i], dir);
			if (cpt < 2 && files->content)
				printf("\n%s:\n", av[i]);
			if (cpt < 2 && av[i + 1] != NULL && !files->data)
				printf("%s:\n", av[i]);
			if ((av[i + 1] == NULL && cpt > 1))
				printf("\n%s:\n", av[i]);
			check_opt(flags, dir);
			i++;	
			continue ;
		}
		i++;
	}
}
