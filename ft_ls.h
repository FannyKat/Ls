/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:51:38 by maboye            #+#    #+#             */
/*   Updated: 2019/02/18 14:18:04 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <curses.h>
# include <dirent.h>
# include <errno.h>
# include <grp.h>
# include <stdint.h>
# include <pwd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <term.h>
# include <termios.h>
# include <time.h>
# include <unistd.h>

# define A_FLAG 1
# define L_FLAG 2
# define R_FLAG 4
# define REV_FLAG 8
# define T_FLAG 16

# define C_FLAG 32
# define D_FLAG 64
# define DOT_FLAG 128
# define F_FLAG 256
# define G_FLAG 512
# define ONE_FLAG 1024
# define U_FLAG 2048
# define FLAG 4096

# include "libft/libft.h"

typedef struct	s_data
{
	long long	total;
	int			link;
	int			uid;
	int			gid;
	int			weight;
	int			flags;
}				t_data;

void			block_bytes(t_list *file);
void			error(char *str);
void			ft_ls(t_list *f_data, char *path, int flags);
void			ft_printf(const char *format, ...);
int			    ft_ls_quicksort(void **add, int start, int size, int choose);
void			**ft_stockaddr(t_list *list, int flags);
void			handle_option(struct stat fd, int flags);
void			how_to_sort(void **addr, int flags, int choose);
int				int_len(int nb);
int				is_dot(char *str, int choose);
void			long_listing(void **addr, int flags, int i);
void			ft_padding(int nb);
int				parsing(int *i, int ac, char **av, int flags);
void			print_list(void **stock, int flags);
void			print_color(struct stat elem, char *str, int flags);
void			print_column(void **stock, int size, int count, int flags);
void			sort_av(char **av);
void			sort_stock(void **av);
void			sort_time(void **av, int choose);
t_list			*stock_list(t_list *f_data, char *path, int flags);

#endif
