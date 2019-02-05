#include "my_ls.h"

void				display(t_list *file, t_list *begin, int size)
{
	begin = file;
	while (file->next)
	{
		file->content = ft_strjoin(file->content, "/");
		file->content = ft_strjoin(file->content, file->data);
		inspect_file(file->content, size);
		file = file->next;
	}
	file = begin;
}

t_list				*check_subdir(t_list *file, DIR *dir, int ac)
{
	t_list			*begin;	

	begin = file;
	while (file->next)
	{
		if (is_notdot(file))
		{
			printf("\n");
			printf("%s:\n", file->content);
			dir = opendir(file->content);
			stock_file(file->content, dir, file);
			block_bytes(file, begin);
			display(file, begin, ac);
		}
		file = file->next;
	}
	file = begin;
	return (0);
}

void					recursive(t_list *file, DIR* dir, int size)
{
	t_list				*current;

	while (file->next)
	{
		current = file;
		file = file->next;
		check_subdir(current, dir, size);
		recursive(file, dir,  size);
	}
}


void					check_dir(t_list *file, char *path, int size, DIR* dir)
{
	t_list				*begin;

	begin = file;
	printf("%s:\n", path);
	stock_file(path, dir, file);
	block_bytes(file, begin);
	display(file, begin, size);
	closedir(dir);
	recursive(file, dir, size);
}
