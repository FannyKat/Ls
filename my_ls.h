#ifndef LS_H
# define LS_H

# include <fcntl.h>
# include "../libft/libft.h"
#include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>

# define FLAG_A 1
# define FLAG_L 2
# define FLAG_R 4
# define FLAG_REV 8
# define FLAG_T 16

typedef struct		s_data
{
	long long		total;
}					t_data;

void			*error(char *str);
void			inspect_file(int flags, char *av);
void			block_bytes(int flags, t_list *file);
int				isdot(char *dot);
void			stock_data(char *path, t_list *av);
void			stock_params(int j, int flags, char **path, t_list *dir, t_list *files);
char			*get_name(char *av);
int				isdir(char *path);
void			print_list(int flags, t_list *files);
int				check_dash(int *i, char **av);
void			walking_files(int flags, t_list *files);
void			sort(t_list *files, int flags);
void			time_sort(int flags, t_list *files);
void			put_colors(struct stat fd, char *path, int flags);

#endif
