/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_16base_large.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmirmuln <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:54:16 by jmirmuln          #+#    #+#             */
/*   Updated: 2021/10/30 18:51:08 by jmirmuln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_16base_large(unsigned int	n)
{
	int		k;
	int		i;
	char	m[11];
	char	*base;

	base = "0123456789ABCDEF";
	i = 0;
	while (n / 16)
	{
		m[i] = base[n % 16];
		n = n / 16;
		i++;
	}
	m[i] = base[n % 16];
	i++;
	k = i;
	while (i-- > 0)
		write(1, &m[i], 1);
	return (k);
}
