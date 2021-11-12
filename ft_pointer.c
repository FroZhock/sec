/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmirmuln <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:54:55 by jmirmuln          #+#    #+#             */
/*   Updated: 2021/10/30 17:20:23 by jmirmuln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_pointer(unsigned long long	n)
{
	int		i;
	int		k;
	char	m[11];
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	while (n / 16)
	{
		m[i] = base[n % 16];
		n = n / 16;
		i++;
	}
	m[i] = base[n % 16];
	i = i + 1;
	k = i;
	ft_putstr("0x");
	while (i-- > 0)
		write(1, &m[i], 1);
	return (k + 2);
}
