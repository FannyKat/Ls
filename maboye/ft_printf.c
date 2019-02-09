/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 05:07:59 by maboye            #+#    #+#             */
/*   Updated: 2019/02/08 13:27:54 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		handle_percent(va_list args, int choose)
{
	char	*str;
	int		nb;

	if (!choose)
	{
		str = va_arg(args, char*);
		str ? ft_putstr(str) : 0;
	}
	else if (choose)
	{
		nb = va_arg(args, int);
		ft_putnbr(nb);
	}
}

void			ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			*(format + 1) == 's' ? handle_percent(args, 0) : 0;
			*(format + 1) == 'd' ? handle_percent(args, 1) : 0;
			format += 2;
		}
		else
			ft_putchar(*format++);
	}
	va_end(args);
}
