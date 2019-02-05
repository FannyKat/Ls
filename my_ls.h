#ifndef LS_H
# define LS_H

#define _GNU_SOURCE
#include <fcntl.h>
#include "libft/libft.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <sys/sysmacros.h>

typedef struct		s_data
{
	long long	total;
}			t_data;

int			main(int ac, char **av);
void			inspect_file(char *av, int size);
void			block_bytes(t_list *file, t_list *begin);
void			check_dir(t_list *file, char *path, int size, DIR *dir);
void			stock_file(char *path, DIR *dir, t_list *file);
int			is_notdot(t_list *file);


#endif
