/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalmasr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:13:21 by naalmasr          #+#    #+#             */
/*   Updated: 2025/02/01 16:16:38 by naalmasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar((n % 10 + '0'));
}

void	ft_putstr(char *k)
{
	int	i;

	i = 0;
	while (k[i] != '\0')
	{
		write(1, &k[i], 1);
		i++;
	}
}

void	ft_start(va_list ap, char k)
{
	int		w;
	char	c;
	char	*g;

	if (k == 'd' || k == 'i')
	{
		w = va_arg(ap, int);
		ft_putnbr(w);
	}
	else if (k == 'c')
	{
		c = va_arg(ap, int);
		ft_putchar(c);
	}
	else if (k == 's')
	{
		g = va_arg(ap, char *);
		ft_putstr(g);
	}
}

int	ft_printf(const char *l, ...)
{
	va_list	ap;
	int		i;
	int		c;

	va_start(ap, l);
	i = 0;
	c = 0;
	while (l[i] != '\0')
	{
		if (l[i] == '%')
		{
			ft_start(ap, l[++i]);
			c++;
		}
		else
		{
			ft_putchar(l[i]);
			c++;
		}
		i++;
	}
	va_end(ap);
	return (c);
}
