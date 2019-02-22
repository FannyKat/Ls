#include "my_ls.h"

int			compare(t_list *curr, t_list *next, int flags)
{
	int		res;

	res = ft_strcmp((char *)curr->data, (char *)next->data);
	if (flags & FLAG_REV)
		return (res < 0 ? 1 : 0);
	else
		return (res > 0 ? 1 : 0);
}

void   		 swap_element(void *elem1, void *elem2)
{
	void	*tmp;

	tmp = elem1;
	elem1 = elem2;
	elem2 = tmp;
}

void			sort(t_list *files, int flags)
{
	t_list		*tmp;
	void		*tmp2;
	void		*tmp3;
	size_t		size;
	int			TRUE;

	if (files == NULL)
		return ;
	TRUE = 1;
	while (TRUE)
	{
		TRUE = 0;
		tmp = files;
		while (tmp->next->data  && tmp->next->content)
		{
			if (compare(tmp, tmp->next, flags))
			{
				tmp2 = tmp->data;
				tmp3 = tmp->content;
				size = tmp->size;
				tmp->data = tmp->next->data;
				tmp->content = tmp->next->content;
				tmp->size = tmp->next->size;
				tmp->next->data = tmp2;
				tmp->next->content = tmp3;
				tmp->next->size = size;
				TRUE = 1;
			}
			if (tmp->next == NULL)
				break ;
			tmp = tmp->next;
		}
		tmp = NULL;
	}
}

int				get_time(t_list *files)
{ 
	struct stat	fd;

	stat(files->content, &fd);
	return (fd.st_mtime);
}

int			compare_rev(int flags, t_list *tmp)
{
	if (flags & FLAG_REV)
		return (get_time(tmp) > get_time(tmp->next));
	return (get_time(tmp) < get_time(tmp->next));
}

void			time_sort(int flags, t_list *files)
{
	t_list		*tmp;
	void		*tmp2;
	void		*tmp3;
	size_t		size;
	int			TRUE;

	TRUE = 1;
	while (TRUE)
	{
		TRUE = 0;
		tmp = files;
		while (tmp->next->data && tmp->next->content)
		{
			if (compare_rev(flags, tmp))
			{
				tmp2 = tmp->data;
				tmp3 = tmp->content;
				size = tmp->size;
				tmp->data = tmp->next->data;
				tmp->content = tmp->next->content;
				tmp->size = tmp->next->size;
				tmp->next->data = tmp2;
				tmp->next->content = tmp3;
				tmp->next->size = size;
				TRUE = 1;
			}
			if (tmp->next == 0)
				break ;
			tmp = tmp->next;
		}
		tmp = NULL;
	}

}
