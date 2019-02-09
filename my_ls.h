#ifndef LS_H
# define LS_H

# define _GNU_SOURCE
# include <fcntl.h>
# include "../libft/libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>

# define FLAG_A 1
# define FLAG_L 2
# define FLAG_R 4
# define FLAG_REV 8
# define FLAG_T 16

typedef struct		s_data
{
	long long		total;
}					t_data;

void			inspect_file(char *av, int size);
void			block_bytes(t_list *file, t_list *begin);
void			check_dir(t_list *file, char *path, int size);
void			stock_file(char *path, t_list *file);
int				is_notdot(t_list *file);
void			stock_dir(char *path, t_list *dir);
void			stock_data(char *path, t_list *av);
char			*get_name(char *av);
void			stock_params(int j, char **path, t_list *params, t_list *dir);
int				isdir(char *path);
void			print_list(t_list *files);
int				check_dash(int *i, char **av);

#endif
