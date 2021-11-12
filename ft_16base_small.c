/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_16base_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmirmuln <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:53:26 by jmirmuln          #+#    #+#             */
/*   Updated: 2021/10/30 17:19:01 by jmirmuln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_16base_small(unsigned int	n)
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
	while (i-- > 0)
		write(1, &m[i], 1);
	return (k);
}
