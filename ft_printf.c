/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmirmuln <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:58:46 by jmirmuln          #+#    #+#             */
/*   Updated: 2021/10/30 18:53:28 by jmirmuln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include "ft_printf.h"

static int	count_words(const char	*s)
{
	int		i;
	float	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == '%' && (s[i + 1] == 'c' || s[i + 1] == 's'
				|| s[i + 1] == 'd' || s[i + 1] == 'i'
				|| s[i + 1] == 'u' || s[i + 1] == 'x' || s[i + 1] == 'X'
				|| s[i + 1] == 'p'))
			k++;
		else if (s[i] == '%' && (s[i + 1] == '%' && s[i + 2] != '%'))
			k++;
		else if (s[i] == '%' && (s[i + 1] == '%' && s[i + 2] == '%'))
		{
			i++;
			k++;
		}
		i++;
	}
	return (i - (k * 2));
}

static int	printer(int	i, int	j, va_list nh, const char	*s)
{
	if (s[j] == '%' && s[j + 1] == 's')
		i += ft_putstr(va_arg(nh, char *));
	else if (s[j] == '%' && s[j + 1] == 'c')
		i += ft_putchar(va_arg(nh, int));
	else if (s[j] == '%' && (s[j + 1] == 'd' || s[j + 1] == 'i'))
		i += ft_putnbr(va_arg(nh, int));
	else if (s[j] == '%' && s[j + 1] == 'u')
		i += ft_unsigned_putnbr(va_arg(nh, unsigned int));
	else if (s[j] == '%' && s[j + 1] == 'x')
		i += ft_16base_small(va_arg(nh, unsigned int));
	else if (s[j] == '%' && s[j + 1] == 'X')
		i += ft_16base_large(va_arg(nh, unsigned int));
	else if (s[j] == '%' && s[j + 1] == '%')
	{
		i += ft_putchar('%');
		i = i * (-1);
	}
	else if (s[j] == '%' && s[j + 1] == 'p')
		i += ft_pointer((unsigned long long)va_arg(nh, void *));
	else if (s[j - 1] != '%' || ((s[j] != '%' && s[j] != 'c' && s[j] != 's'
				&& s[j] != 'd' && s[j] != 'i' && s[j] != 'p'
				&& s[j] != 'x' && s[j] != 'X'
				&& s[j] != 'u') && s[j - 1] == '%' && s[j - 2] == '%'))
		write(1, &s[j], 1);
	return (i);
}

int	ft_printf(const char	*s, ...)
{
	int		j;
	int		i;
	va_list	nh;

	va_start(nh, s);
	j = 0;
	i = 0;
	while (s[j])
	{
		i = printer(i, j, nh, s);
		if (i < 0)
		{
			j++;
			i = i * (-1);
		}
		j++;
	}
	va_end(nh);
	return (i + count_words(s));
}
