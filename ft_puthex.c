/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlenoch <nlenoch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:35:57 by nlenoch           #+#    #+#             */
/*   Updated: 2021/08/17 18:33:51 by nlenoch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(unsigned long n, char prc)
{
	int			i;

	i = 0;
	if (prc == 'p')
		i = 2;
	if (n == 0)
		i++;
	while (n > 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

int	ft_puthex(unsigned long n, char prc)
{
	char		c;
	int			i;
	int			d;

	i = ft_nbrlen(n, prc);
	if (n >= 16)
		ft_puthex(n / 16, prc);
	d = (n % 16);
	if (d < 10)
		c = d + 48;
	else if (prc == 'X')
		c = d + 55;
	else if (prc == 'p' || prc == 'x')
		c = d + 87;
	write(1, &c, 1);
	return (i);
}
