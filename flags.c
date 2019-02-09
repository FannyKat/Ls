#include "my_ls.h"

int				check_flags(int flags, char *av)
{
	int			i;

	i = 0;
	while (av[i++])
	{
		if (av[i] == 'a' && !(flags & FLAG_A))
			flags += FLAG_A;
		if (av[i] == 'l' && !(flags & FLAG_L))
			flags += FLAG_L;
		if (av[i] == 'R' && !(flags & FLAG_R))
			flags += FLAG_R;
		if (av[i] == 'r' && !(flags & FLAG_REV))
			flags += FLAG_REV;
		if (av[i] == 't' && !(flags & FLAG_T))
			flags += FLAG_T;
	}
	return (flags);
}

int				check_dash(int *i, char **av)
{
	int			flags;

	flags = 0;
	while (av[*i])
	{
		if (av[*i][0] == '-')
		{
			if (av[*i][1] == '-')
			{
				(*i)++;
				return (0);
			}
			flags += check_flags(flags, av[*i]);
			(*i)++;
		}
		else
			return (0);
	}
	return (flags);
}
