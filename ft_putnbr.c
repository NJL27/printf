/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:05:20 by nlenoch           #+#    #+#             */
/*   Updated: 2021/08/17 18:59:54 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(int n)
{
	int			i;

	i = 0;
	if (n <= 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	char		c;
	int			i;

	i = ft_nbrlen(n);
	if (n < 0)
	{
		write(1, "-", 1);
		if (n == -2147483648)
		{
			write(1, "2147483648", 10);
			return (11);
		}
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (i);
}
