/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:51:38 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 23:33:17 by maboye           ###   ########.fr       */
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
# define C_FLAG 2
# define L_FLAG 4
# define R_FLAG 8
# define REV_FLAG 16
# define T_FLAG 32

# include "libft/libft.h"

typedef struct	s_data
{
	long long	total;
}				t_data;

void			block_bytes(t_list *file, int flags);
int				check_flags(char *str, int src);
void			error(char *str);
void			ft_free_table(void **table);
void			ft_ls(t_list *f_data, char *path, int flags);
void			ft_printf(const char *format, ...);
int				is_dot(char *str);
void			long_listing(char *path);
void			print_list(void **stock);
void			print_column(void **stock, int size, int count);
void			sort_av(char **av);
void			sort_stock(void **av);
void			sort_time(void **av);
t_list			*stock_list(t_list *f_data, char *path, int flags);
int				term_size(int fd);

#endif
