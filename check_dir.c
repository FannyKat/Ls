#include "my_ls.h"

void				display(t_list *file, t_list *begin)
{
	begin = file;
	while (file->next)
	{
		file->content = ft_strjoin(file->content, "/");
		file->content = ft_strjoin(file->content, file->data);
	//	inspect_file(file->content, size);
		file = file->next;
	}
	file = begin;
}

t_list				*check_subdir(t_list *file)
{
	t_list			*begin;	
	DIR				*dir;

	begin = file;
	while (file->next)
	{
		if (is_notdot(file))
		{
			//stock_files(file->content, file);
			printf("\n");
			printf("%s:\n", file->content);
			dir = opendir(file->content);
	//		block_bytes(file, begin);
			display(file, begin);
		}
		file = file->next;
	}
	file = begin;
	return (0);
}

void					recursive(t_list *file, int size)
{
	t_list				*current;

	while (file->next)
	{
		current = file;
		file = file->next;
		if (is_notdot(current))
			check_subdir(current);
		printf("%s \n", file->content);
		recursive(file,  size);
	}
}


void					check_dir(t_list *file, char *path, int size)
{
	t_list				*begin;

	begin = file;
	printf("%s:\n", path);
//	stock_files(path, file);
	block_bytes(file, begin);
	display(file, begin);
	recursive(file, size);
}
