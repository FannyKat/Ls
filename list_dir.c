#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>

int					main(int ac, char **av)
{
	DIR*			dir;
	struct dirent* 	current;

	if (ac == 2)
	{
		dir = opendir(av[1]);
		while ((current = readdir(dir)))
		{
			if (current->d_name[0] != '.')
				printf("%s\n", current->d_name);
		}
		closedir(dir);
	}
	return (0);
}
