#include <sys/stat.h>
#include <stdio.h>

int 	main(int ac, char **av)
{
	struct stat *buf;

	if (ac == 2)
	{
		while (stat(av[1], buf) > 0)
		{
			printf("%s\t%s\t", buf->st_uid, buf->st_size);
		}
	}
	return (0);
}
