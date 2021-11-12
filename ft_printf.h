/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liba.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmirmuln <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:59:43 by jmirmuln          #+#    #+#             */
/*   Updated: 2021/10/30 17:31:40 by jmirmuln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int	ft_16base_large(unsigned int	n);
int	ft_16base_small(unsigned int	n);
int	ft_pointer(unsigned long long	n);
int	ft_putchar(char	s);
int	ft_putnbr(int	n);
int	ft_putstr(char	*s);
int	ft_unsigned_putnbr(unsigned int	n);
int	ft_printf(const char	*s, ...);
#endif
