/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmirmuln <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:56:49 by jmirmuln          #+#    #+#             */
/*   Updated: 2021/10/30 16:57:06 by jmirmuln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_not_min_zero(char	*m, int	n)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (n < 0)
	{
		write (1, "-", 1);
		n = n * -1;
		k = 1;
	}
	while (n)
	{
		m[i] = (char)((n % 10) + '0');
		n = n / 10;
		i++;
	}
	k = k + i;
	while (i-- > 0)
		write(1, &m[i], 1);
	return (k);
}

int	ft_putnbr(int n)
{
	int		i;
	char	m[12];

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else
	{
		i = put_not_min_zero(m, n);
		return (i);
	}
}
