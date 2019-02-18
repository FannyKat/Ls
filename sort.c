#include "my_ls.h"

int			compare(t_list *curr, t_list *next, int flags)
{
	char		*temp1;
	char		*temp2;
	int		res;

	temp1 = ft_strtolower(ft_strdup(curr->data));
	temp2 = ft_strtolower(ft_strdup(next->data));
	res = ft_strcmp(temp1, temp2);
	free(temp1);
	free(temp2);
	if (flags & FLAG_REV)
		return (res < 0 ? 1 : 0);
	else
		return (res > 0 ? 1 : 0);
}

void			sort(t_list *files, int flags)
{
	t_list		*tmp;
	void		*tmp2;
	void		*tmp3;
	int		TRUE;

	if (files == NULL)
		return ;
	TRUE = 1;
	while (TRUE)
	{
		TRUE = 0;
		tmp = files;
		while (tmp->next->data != NULL)
		{
			if (compare(tmp, tmp->next, flags) > 0)
			{
				tmp2 = tmp->data;
				tmp3 = tmp->content;
				tmp->data = tmp->next->data;
				tmp->content = tmp->next->content;
				tmp->next->data = tmp2;
				tmp->next->content = tmp3;
				TRUE = 1;
			}
			tmp = tmp->next;
			if (tmp->next == 0)
				break ;
		}
		tmp = NULL;
	}
}

int			get_time(t_list *files)
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
	int		TRUE;

	TRUE = 1;
	while (TRUE)
	{
		TRUE = 0;
		tmp = files;
		while (tmp->next->data)
		{
			if (compare_rev(flags, tmp))
			{
				tmp2 = tmp->data;
				tmp3 = tmp->content;
				tmp->data = tmp->next->data;
				tmp->content = tmp->next->content;
				tmp->next->data = tmp2;
				tmp->next->content = tmp3;
				TRUE = 1;
			}
			tmp = tmp->next;
			if (tmp->next == 0)
				break ;
		}
		tmp = NULL;
	}

}
