/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmirmuln <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:56:09 by jmirmuln          #+#    #+#             */
/*   Updated: 2021/10/30 16:56:35 by jmirmuln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_putnbr(unsigned int	n)
{
	int		i;
	int		k;
	char	m[11];

	i = 0;
	while (n / 10)
	{
		m[i] = (char)((n % 10) + '0');
		n = n / 10;
		i++;
	}
	m[i] = (char)((n % 10) + '0');
	i = i + 1;
	k = i;
	while (i-- > 0)
		write(1, &m[i], 1);
	return (k);
}
