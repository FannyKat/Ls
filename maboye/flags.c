/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 23:11:47 by maboye            #+#    #+#             */
/*   Updated: 2019/02/11 09:46:20 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		bonus_flags(char c, int flags)
{
	if (c == 'C' && !(flags & C_FLAG))
		flags += C_FLAG;
	else if (c == 'g' && !(flags & FLAG))
		flags += FLAG;
	if (c == '1' && !(flags & ONE_FLAG))
	{
		flags = (flags & L_FLAG) ? flags -= L_FLAG : flags;
		flags = (flags & C_FLAG) ? flags -= C_FLAG : flags;
		flags = (flags & FLAG) ? flags -= FLAG : flags;
	}
	else if (c == 'A' && !(flags & DOT_FLAG))
		flags += DOT_FLAG;
	else if (c == 'd' && !(flags & D_FLAG))
		flags += D_FLAG;
	else if (c == 'f' && !(flags & F_FLAG))
		flags += F_FLAG;
	else if (c == 'G' && !(flags & G_FLAG))
		flags += G_FLAG;
	else if (c == 'u' && !(flags & U_FLAG))
		flags += U_FLAG;
	else
		flags = flags == 0 ? -1 : flags;
	return (flags);
}

static int		check_flags(char *str, int flags)
{
	int		i;

	i = 0;
	while (str[++i])
	{
		if (str[i] == 'a' && !(flags & A_FLAG))
			flags += A_FLAG;
		else if (str[i] == 'l' && !(flags & L_FLAG))
			flags += L_FLAG;
		else if (str[i] == 'R' && !(flags & R_FLAG))
			flags += R_FLAG;
		else if (str[i] == 'r' && !(flags & REV_FLAG))
			flags += REV_FLAG;
		else if (str[i] == 't' && !(flags & T_FLAG))
			flags += T_FLAG;
		else if (bonus_flags(str[i], flags) == -1)
			error("ls: illegal option error\
			\nusage: ls [ -1AaCdfGglRtu -- ] [file ...]");
		else
			flags = bonus_flags(str[i], flags);
	}
	return ((flags & F_FLAG) ? A_FLAG + C_FLAG + F_FLAG + R_FLAG : flags);
}

int				parsing(int *i, int ac, char **av, int flags)
{
	while (++(*i) < ac && av[*i][0] == '-' && av[*i][1])
	{
		if (av[*i][1] == '-')
		{
			(*i)++;
			return (flags);
		}
		flags = check_flags(av[*i], flags);
	}
	(flags & C_FLAG) && !isatty(STDOUT_FILENO) ? flags -= C_FLAG : 0;
	return (flags);
}
