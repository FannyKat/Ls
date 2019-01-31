# ifndef LS_H
#define LS_H

#include "libft/libft.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>
#include <string.h>

typedef struct		s_data
{
	long long		total;
}					t_data;

int					main(int ac, char **av);

#endif
